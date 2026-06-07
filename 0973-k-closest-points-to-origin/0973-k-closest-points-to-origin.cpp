class cmp{
    public:
       bool operator()(vector<int> a,vector<int> b){
        return a[0]<b[0];
       }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        
        priority_queue<vector<int>,vector<vector<int>>,cmp> q;

        for(auto it : points){
            int sqr=it[0]*it[0]+it[1]*it[1];
            q.push({sqr,it[0],it[1]});
            if(q.size()>k){
                q.pop();
            }
        }
       vector<vector<int>> ans;
       while(!q.empty()){
        auto it =q.top();
        ans.push_back({it[1],it[2]});
        q.pop();
       }
       return ans;
    }
};