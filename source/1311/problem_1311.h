#pragma once

#include <vector>
#include <string>

using VideoList = std::vector<std::string>;
using FriendList = std::vector<int>;
using FriendNetwork = std::vector<FriendList>;

FriendList FindFriendsAtLevel(FriendNetwork const& friendNetwork,
                              int id,
                              int const level);

VideoList GetWatchedVideos(FriendList const& friendList,
                           std::vector<VideoList> const& watchedVideos);

VideoList WatchedVideosByFriends(std::vector<VideoList>& watchedVideos,
                                 std::vector<FriendList>& friends,
                                 int id,
                                 int level);