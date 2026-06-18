class Solution {
public:

    static bool cmp(pair<string,int>& a,
                    pair<string,int>& b){

        if(a.second == b.second)
            return a.first < b.first;

        return a.second > b.second;
    }

    vector<string> topKFrequent(vector<string>& words,
                                int k) {

        unordered_map<string,int> mp;

        for(auto &word : words)
            mp[word]++;

        vector<pair<string,int>> freq;

        for(auto &it : mp)
            freq.push_back(it);

        sort(freq.begin(),
             freq.end(),
             cmp);

        vector<string> ans;

        for(int i=0;i<k;i++)
            ans.push_back(freq[i].first);

        return ans;
    }
};