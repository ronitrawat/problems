class Twitter {
public:

    int timer;

    unordered_map<int, unordered_set<int>> followMap;

    unordered_map<int, vector<pair<int,int>>> tweetMap;
    // user -> {(time, tweetId)}

    Twitter() {
        timer = 0;
    }

    void postTweet(int userId, int tweetId) {

        tweetMap[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<vector<int>> pq;

        followMap[userId].insert(userId);

        for(auto followee : followMap[userId]) {

            if(tweetMap[followee].empty())
                continue;

            int idx = tweetMap[followee].size() - 1;

            pq.push({
                tweetMap[followee][idx].first,   
                tweetMap[followee][idx].second,  
                followee,                        
                idx                             
            });
        }

        vector<int> ans;

        while(!pq.empty() && ans.size() < 10) {

            auto curr = pq.top();
            pq.pop();

            int tweetId = curr[1];
            int user = curr[2];
            int idx = curr[3];

            ans.push_back(tweetId);

            if(idx > 0) {

                pq.push({
                    tweetMap[user][idx - 1].first,
                    tweetMap[user][idx - 1].second,
                    user,
                    idx - 1
                });
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {

        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        if(followerId != followeeId)
            followMap[followerId].erase(followeeId);
    }
};