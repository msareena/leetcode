#include <problem_1311.h>

#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>

FriendList FindFriendsAtLevel(FriendNetwork const& friendNetwork,
                              int id,
                              int const level)
{
    std::deque<int> Q;
    std::unordered_set<int> V;

    int current_level = 0;
    Q.push_back(id);
    V.insert(id);

    while (current_level < level)
    {
        int const size = Q.size();

        for (int i = 0; i < size; ++i) {
            int const curr_id = Q.front();
            Q.pop_front();

            for (auto friend_id: friendNetwork[curr_id]) {
                if (V.find(friend_id) == V.end()) {
                    Q.push_back(friend_id);
                    V.insert(friend_id);
                }
            }
        }

        ++current_level;
    }

    return FriendList(Q.begin(), Q.end());
}

struct WatchedVideosComparator
{
    bool operator()(std::pair<std::string, int> const& lhs,
                    std::pair<std::string, int> const& rhs)
    {
        return lhs.second > rhs.second ||
                (lhs.second == rhs.second && lhs.first > rhs.first);
    }
};

VideoList GetWatchedVideos(FriendList const& friendList,
                           std::vector<VideoList> const& watchedVideos)
{
    std::unordered_map<std::string, int> watchedVideosCount;

    for (auto friend_id : friendList) {
        for (auto& video: watchedVideos[friend_id]) {
            watchedVideosCount[video] += 1;
        }
    }

    std::priority_queue<std::pair<std::string, int>,
                        std::vector<std::pair<std::string, int>>,
                        WatchedVideosComparator> PQ;
    for (auto& videoCount : watchedVideosCount) {
        PQ.push(videoCount);
    }

    VideoList videoList;
    while (!PQ.empty()) {
        videoList.push_back(PQ.top().first);
        PQ.pop();
    }

    return videoList;
}

VideoList WatchedVideosByFriends(std::vector<VideoList>& watchedVideos,
                                 std::vector<FriendList>& friends,
                                 int id,
                                 int level)
{
    FriendList friendsAtLevel = FindFriendsAtLevel(friends, id, level);
    return GetWatchedVideos(friendsAtLevel, watchedVideos);
}