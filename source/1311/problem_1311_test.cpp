#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <problem_1311.h>

VideoList WatchedVideosByFriends(std::vector<VideoList>& watchedVideos,
                                 std::vector<FriendList>& friends,
                                 int id,
                                 int level);

TEST(WatchedVideosByFriends, TestCase1)
{
    std::vector<VideoList> watchedVideos {
        {"A", "B"}, {"C"}, {"B", "C"}, {"D"}
    };

    std::vector<FriendList> friends {
        {1, 2}, {0, 3}, {0, 3}, {1, 2}
    };

    VideoList videoList = WatchedVideosByFriends(watchedVideos,
                                                 friends,
                                                 0,
                                                 1);

    ASSERT_THAT(videoList, ::testing::ElementsAre("B", "C"));
}

TEST(WatchedVideosByFriends, TestCase2)
{
    std::vector<VideoList> watchedVideos {
        {"A", "B"}, {"C"}, {"B", "C"}, {"D"}
    };

    std::vector<FriendList> friends {
        {1, 2}, {0, 3}, {0, 3}, {1, 2}
    };

    VideoList videoList = WatchedVideosByFriends(watchedVideos,
                                                 friends,
                                                 0,
                                                 2);

    ASSERT_THAT(videoList, ::testing::ElementsAre("D"));
}