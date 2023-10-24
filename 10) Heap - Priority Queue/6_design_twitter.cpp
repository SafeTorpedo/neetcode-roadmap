#include <bits/stdc++.h>
using namespace std;

class Twitter
{
public:
    Twitter()
    {
    }

    void postTweet(int userId, int tweetId)
    {
        tweets.push_back({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        int count = 10;
        vector<int> ans;

        for (int i = tweets.size() - 1; i >= 0; i--)
        {
            if (count == 0)
                break;

            int postUserId = tweets[i].first;
            int tweetId = tweets[i].second;
            unordered_set<int> following = followers[userId];
            if (following.find(postUserId) != following.end() || postUserId == userId)
            {
                ans.push_back(tweetId);
                count--;
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId)
    {
        followers[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        followers[followerId].erase(followeeId);
    }

private:
    unordered_map<int, unordered_set<int>> followers;
    vector<pair<int, int>> tweets;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */