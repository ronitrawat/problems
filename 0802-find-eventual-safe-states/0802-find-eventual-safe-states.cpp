class Solution {
public:
    bool dfs(int node,vector<vector<int>> &graph,vector<int> &visited,vector<int> &current){
        visited[node]=1;
        current[node]=1;

        for(int neigh:graph[node]){
            if(!visited[neigh]){
                bool hasCycle=dfs(neigh,graph,visited,current);
                if(hasCycle){
                    return true;
                }

            }
            else{
                if(current[neigh]==1){
                    return true;
                }
            }

        }
        current[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> visited(graph.size());
        vector<int> ans;
        vector<int> current(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            if(!visited[i]){
                dfs(i,graph,visited,current);
            }
        }
        
        for(int i=0;i<graph.size();i++){
            if(current[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};