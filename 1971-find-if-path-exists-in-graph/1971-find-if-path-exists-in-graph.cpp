class Solution {
public:

    void dfs(vector<int> & visited,vector<vector<int>> &graph,int source){
        visited[source]=1;
        for(int neigh:graph[source]){
            if(!visited[neigh]){
                dfs(visited,graph,neigh);
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        vector<int> visited(n,0);

        for(int i=0;i<edges.size();i++){
            int a =edges[i][0];
            int b=edges[i][1];

            graph[a].push_back(b);
            graph[b].push_back(a);

        }
        dfs(visited,graph,source);

        return visited[destination];
    }
};