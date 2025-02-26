class Twitter {
private:
    unordered_map<int, vector<pair<int, int>>> userTweets;
    unordered_map<int, unordered_set<int>> userFollowers;
    int timestamp;
public:
    Twitter() {
        this->timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({timestamp, tweetId});
        this->timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        userFollowers[userId].insert(userId);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(const int & followeeId : userFollowers[userId]){
            for(const auto & p : userTweets[followeeId]){
                const int timestamp = p.first;
                const int tweetId = p.second;
                if(pq.size() < 10){
                    pq.push({timestamp, tweetId});

                } else if (timestamp > pq.top().first){
                    pq.pop();
                    pq.push({timestamp, tweetId});
                }
            }
        }

        vector<int> ans(pq.size());
        for(int i = ans.size() - 1; i >= 0; i--){
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        userFollowers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        userFollowers[followerId].erase(followeeId);
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