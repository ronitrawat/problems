class Solution {
public:

    void bfs(vector<int> & visited,vector<vector<int>> &graph,int source){
        visited[source]=1;
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            int f=q.front();
            q.pop();
            for(int neigh:graph[f]){
                if(!visited[neigh]){
                    visited[neigh]++;
                    q.push(neigh);
                }
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
        bfs(visited,graph,source);

        return visited[destination];
    }
};