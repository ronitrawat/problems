class Solution {
public:
 
    void dfs(int node,vector<vector<int>> &forward,vector<vector<int>> &backward,int &ans,vector<int> &visited){
    
    visited[node]=1;
    for(int neig:forward[node]){
        if(!visited[neig]){
            ans+=1;
          
            dfs(neig,forward,backward,ans,visited);
        }
    }
    for(int neig:backward[node]){
        if(!visited[neig]){
           
            dfs(neig,forward,backward,ans,visited);
            
        }
    }

    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> forward(n);
        vector<vector<int>> backward(n);
        vector<int> visited(n,0);
        for(auto it : connections){
            int a=it[0];
            int b=it[1];
            forward[a].push_back(b);
            backward[b].push_back(a);

        }
        int ans=0;
        dfs(0,forward,backward,ans,visited);

        return ans;


    }
};