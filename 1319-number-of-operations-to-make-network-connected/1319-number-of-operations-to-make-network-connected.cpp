class Solution {
public:
    void dfs(int node,vector<vector<int>> & adj,vector<int> &visited){
       visited[node]=1;
       for(auto neigh:adj[node]){
       
        if(!visited[neigh]){
         dfs(neigh,adj,visited);
        }
        }

    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        vector<vector<int>> adj(n);
        vector<int> visited(n,0);

        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=0;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj,visited);
                ans+=1;
            }
        }

        return ans-1;
    }
};