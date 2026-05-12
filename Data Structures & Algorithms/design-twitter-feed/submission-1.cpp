#define PII pair<int,int>
class Twitter {
    unordered_map<int, unordered_set<int>> follower_map;
    unordered_map<int, vector<PII>> postTweet_map;
    int time = 0;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        this->postTweet_map[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        unordered_set<int> followees = this->follower_map[userId];
        followees.insert(userId);
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        
        for (auto followee : followees) {
            for (pair<int,int> obj : this->postTweet_map[followee]) {
                pq.push(obj);
                if (pq.size() > 10) {
                    pq.pop();
                }
            }
        }

        // Insert own tweet
        // for (pair<int,int> obj : this->postTweet_map[userId]) {
        //         pq.push(obj);
        //         if (pq.size() > 10) {
        //             pq.pop();
        //         }
        // }

        vector<int> res(pq.size());
        int i = pq.size() - 1;
        while (!pq.empty()) {
            res[i] = pq.top().second;
            pq.pop();
            i--;
        }

        
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        this->follower_map[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        this->follower_map[followerId].erase(followeeId);
    }
};
