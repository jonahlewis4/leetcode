class Twitter {
private:
    class User {
        private:
            int id;
            unordered_set<int> following;
            unordered_set<int> followers;
            unordered_set<int> tweets;

        public:
            User(int id){
                this->id = id;
                this->follow(this->id);
                this->addFollower(this->id);
            }
            void follow(int followeeId){
                following.insert(followeeId);
            }
            void unFollow(int followeeId){
                following.erase(followeeId);
            }

            void addFollower(int followerId){
                followers.insert(followerId);
            }
            void removeFollower(int followerId){
                followers.erase(followerId);
            }
            void addTweet(int tweetId){
                tweets.insert(tweetId);
            }
            const bool isFollowing(int followeeId) const{
                if(following.find(followeeId) == following.end()){
                    return false;
                }
                return true;
            }
            const int UserId() const{
                return this->id;
            }
            const unordered_set<int>& Following() const {
                return following;
            }
            const unordered_set<int>& Tweets() const {
                return tweets;
            }


    };
    class Tweet {
        private:
            int tweetId;
            int userId;
            int timestamp;
        public:
            Tweet(int tweetId, int userId, int timestamp){
                this->tweetId = tweetId;
                this->userId = userId;
                this->timestamp = timestamp;
            }
            const int UserId() const {
                return this->userId;
            }
            const int TweetId() const{
                return this->tweetId;
            }
            const int Timestamp() const{
                return this->timestamp;
            }
            const unique_ptr<Tweet> Copy() const{
                return make_unique<Tweet>(tweetId, userId, timestamp);
            }
        
    };
    unordered_map<int, unique_ptr<User>> users;
    unordered_map<int, unique_ptr<Tweet>> tweets;

    void addUserIfDoesntExist(int userId){
        if(users.find(userId) == users.end()){
            users[userId] = make_unique<User>(userId);
        }
    }

    int timestamp;
    
public:
    Twitter() {
        this->timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        addUserIfDoesntExist(userId);
        users[userId]->addTweet(tweetId);
        this->timestamp++;
        tweets[tweetId] = make_unique<Tweet>(tweetId, userId, this->timestamp);
    }
    
    vector<int> getNewsFeed(int userId) {
        addUserIfDoesntExist(userId);
        const auto cmp = [](const auto & a, const auto & b){
            return a->Timestamp() > b->Timestamp();
        };
        priority_queue<unique_ptr<Tweet>,  vector<unique_ptr<Tweet>>, decltype(cmp)> pq;


        const auto following = users[userId]->Following();
        for(const auto &userId : following){
            const auto &user = users[userId];
            const auto tweetz = user->Tweets();
            for(const auto & tweetId : tweetz){
                if(pq.size() < 10){
                    pq.push(make_unique<Tweet>(tweetId, userId, this->tweets[tweetId]->Timestamp()));
                } else if (this->tweets[tweetId]->Timestamp() > pq.top()->Timestamp()){
                    pq.push(make_unique<Tweet>(tweetId, userId, this->tweets[tweetId]->Timestamp()));
                    pq.pop();
                }
            }
        }

        vector<int> ans(pq.size());
        for(int i = ans.size() - 1; i >= 0; i--){
            ans[i] = pq.top()->TweetId();
            pq.pop();
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        addUserIfDoesntExist(followerId);
        addUserIfDoesntExist(followeeId);
        users[followerId]->follow(followeeId);
        users[followeeId]->addFollower(followerId);

    }
    
    void unfollow(int followerId, int followeeId) {
        addUserIfDoesntExist(followerId);
        addUserIfDoesntExist(followeeId);
        users[followerId]->unFollow(followeeId);
        users[followeeId]->removeFollower(followerId);
    }

    void printUsers() const{
        cout<<"___________________________________"<<endl;
        for(const auto & p : users){
            const auto &user = p.second;
            cout<<"User id: "<<user->UserId()<<endl;
        }
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