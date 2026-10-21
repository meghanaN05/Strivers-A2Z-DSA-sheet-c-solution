#include <bits/stdc++.h>
using namespace std;
class Twitter
{
public:
  unordered_map<int, vector<pair<int, int>>> tweets;
  unordered_map<int, unordered_set<int>> following;
  int time;
  Twitter()
  {
    time = 0;
  }

  void postTweet(int userId, int tweetId)
  {
    tweets[userId].push_back({time++, tweetId});
  }

  vector<int> getNewsFeed(int userId)
  {
    priority_queue<pair<int, int>> pq;
    for (auto &t : tweets[userId])
    {
      pq.push(t);
    }
    for (int followee : following[userId])
    {
      for (auto &t : tweets[followee])
      {
        pq.push(t);
      }
    }
    vector<int> res;
    while (!pq.empty() && res.size() < 10)
    {
      res.push_back(pq.top().second);
      pq.pop();
    }

    return res;
  }

  void follow(int followerId, int followeeId)
  {
    if (followerId != followeeId)
      following[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId)
  {
    following[followerId].erase(followeeId);
  }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// gfg
class Twitter
{
public:
  unordered_map<int, vector<pair<int, int>>> tweets;
  unordered_map<int, unordered_set<int>> following;
  int time;
  Twitter()
  {
    // Code Here
    time = 0;
  }

  void postTweet(int userId, int tweetId)
  {
    // Code Here
    tweets[userId].push_back({time++, tweetId});
  }

  // Retrieve the 10 most recent tweet ids
  vector<int> getNewsFeed(int userId)
  {
    // Code Here
    priority_queue<pair<int, int>> pq;
    for (auto &t : tweets[userId])
    {
      pq.push(t);
    }
    for (int f : following[userId])
    {
      for (auto &t : tweets[f])
      {
        pq.push(t);
      }
    }
    vector<int> res;
    while (!pq.empty() && res.size() < 10)
    {
      res.push_back(pq.top().second);
      pq.pop();
    }
    return res;
  }

  // Follower follows a followee.
  void follow(int followerId, int followeeId)
  {
    // Code Here
    if (followerId != followeeId)
    {
      following[followerId].insert(followeeId);
    }
  }

  // Follower unfollows a followee.
  void unfollow(int followerId, int followeeId)
  {
    // Code Here
    if (followerId != followeeId)
    {
      following[followerId].erase(followeeId);
    }
  }
};