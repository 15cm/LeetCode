class Twitter {
    struct Tweet {
        int tid;
        int ts;
        Tweet(int tid, int ts): tid(tid), ts(ts) {}

        bool operator < (const Tweet& rhs) const {
            return ts > rhs.ts;
        }
    };

    int timestamp;
    unordered_map<int, vector<Tweet>> tweetMap;
    unordered_map<int, unordered_set<int>> followMap;

    void getTop10Tweets(priority_queue<Tweet>& pq, vector<Tweet>& tweets) {
        for(auto& tweet: tweets) {
            if(pq.size() < 10) {
                pq.push(tweet);
            } else if(tweet.ts > pq.top().ts) {
                pq.pop();
                pq.push(tweet);
            }
        }
    }
public:
    /** Initialize your data structure here. */
    Twitter() {
        timestamp = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back(Tweet(tweetId, timestamp++));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet> pq;
        auto& followings = followMap[userId];
        for(int uid: followings) {
            getTop10Tweets(pq, tweetMap[uid]);
        }
        if(!followings.count(userId)) {
            getTop10Tweets(pq, tweetMap[userId]);
        }

        vector<int> res;
        while(!pq.empty()) {
            res.push_back(pq.top().tid);
            pq.pop();
        }
        reverse(res.begin(), res.end());
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
