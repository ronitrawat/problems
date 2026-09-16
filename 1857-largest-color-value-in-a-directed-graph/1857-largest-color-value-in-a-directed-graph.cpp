class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<vector<int>> graph(n);
        vector<vector<int>> cnt(n,vector<int>(26,0));
        vector<int> indegree(n);

        int ans=0;

        for(auto it: edges){
            graph[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int processed=0;
        while(!q.empty()){
            int f=q.front();
            q.pop();
            processed++;

            cnt[f][colors[f]-'a']++;

            ans=max(ans,cnt[f][colors[f]-'a']);

            for(int neigh:graph[f]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }

                for(int i=0;i<26;i++){
                    cnt[neigh][i]=max(cnt[neigh][i],cnt[f][i]);
                }
            }
        }
        return processed==n?ans:-1;

    }
};