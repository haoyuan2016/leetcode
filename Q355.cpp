class Tweet{
    friend class Twitter;
    friend class Compare;
private:
    int id;
    int time;
public:
    Tweet(int id, int time) : id(id), time(time){}
};
class Compare{
public:
    bool operator()(pair<vector<Tweet>::iterator, vector<Tweet>::iterator> p1, pair<vector<Tweet>::iterator, vector<Tweet>::iterator> p2)
    {
         return (p1.first->time < p2.first->time);
    }
};
class Twitter {
private:
    int time;
    unordered_map<int, unordered_set<int>> followmap;
    unordered_map<int, vector<Tweet>> tweets;
public:
    /** Initialize your data structure here. */
    Twitter(int time = 0):time(time){}
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].insert(tweets[userId].begin(), Tweet(tweetId, time++));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<vector<Tweet>::iterator, vector<Tweet>::iterator>, vector<pair<vector<Tweet>::iterator, vector<Tweet>::iterator>>, Compare> pq;
        vector<int> res;
        for(auto follower: followmap[userId]){
            if(tweets.find(follower) != tweets.end() && !tweets[follower].empty())
                pq.push(make_pair(tweets[follower].begin(), tweets[follower].end()));
        }
        if(tweets.find(userId) != tweets.end() && !tweets[userId].empty())
            pq.push(make_pair(tweets[userId].begin(), tweets[userId].end()));
        for(int i = 0; i < 10 && !pq.empty(); i++)
        {
            auto tmp = pq.top();
            pq.pop();
            res.push_back(tmp.first->id);
            if(++tmp.first != tmp.second) pq.push(tmp);
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) followmap[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followmap.find(followerId) != followmap.end()) followmap[followerId].erase(followeeId);
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
// An update version
class Tweet{
    friend class Twitter;
    friend class Compare;
private:
    int id;
    int time;
public:
    Tweet(int id, int time) : id(id), time(time){}
};
class Compare{
public:
    bool operator()(Tweet t1, Tweet t2)
    {
         return (t1.time < t2.time);
    }
};
class Twitter {
private:
    int time;
    unordered_map<int, unordered_set<int>> followmap;
    unordered_map<int, vector<Tweet>> tweets;
public:
    /** Initialize your data structure here. */
    Twitter(int time = 0):time(time){}
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(Tweet(tweetId, time++));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet, vector<Tweet>, Compare> pq;
        vector<int> res;
        for(auto follower: followmap[userId]){
            if(tweets.find(follower) != tweets.end() && !tweets[follower].empty())
            {
                for(auto i : tweets[follower])
                    pq.push(i);
            }
        }
        if(tweets.find(userId) != tweets.end() && !tweets[userId].empty())
        {
            for(auto i : tweets[userId])
                pq.push(i); 
        }
        for(int i = 0; i < 10 && !pq.empty(); i++)
        {
            auto tmp = pq.top();
            pq.pop();
            res.push_back(tmp.id);
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) followmap[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followmap.find(followerId) != followmap.end()) followmap[followerId].erase(followeeId);
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
