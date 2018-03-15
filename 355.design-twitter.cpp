class Twitter {
    struct Tweet {
        int uid, tid;
        Tweet(int uid, int tid): uid(uid), tid(tid) {}
    };

    vector<Tweet> tweets;
    unordered_map<int, unordered_set<int>> followMap;
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets.push_back(Tweet(userId, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        bool hasFollowee = followMap.count(userId);
        for(int cnt = 0, i = tweets.size() - 1; i >= 0 && cnt < 10; i--) {
            auto& tweet = tweets[i];
            if(hasFollowee && followMap[userId].count(tweet.uid) || tweet.uid == userId) {
                res.push_back(tweet.tid);
                cnt++;
            }
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
