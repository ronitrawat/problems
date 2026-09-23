class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<vector<pair<int,int>>> graph(n);

       for(int i=0;i<flights.size();i++){
        int from=flights[i][0];
        int to=flights[i][1];
        int wt=flights[i][2];

        graph[from].push_back({to,wt});
       } 

       queue<vector<int>> pq;
       vector<int> dist(n,INT_MAX);
       
       pq.push({0,src,0});

       while(!pq.empty()){
        auto pr=pq.front();
        pq.pop();
        int stops=pr[0];
        int node=pr[1];
        int distance=pr[2];

        if(stops>k){
            continue;
        }

        for(auto neigh_info: graph[node]){
            int neigh=neigh_info.first;
            int wt=neigh_info.second;

            int new_dist=distance+wt;
            if(new_dist<dist[neigh]){
                dist[neigh]=new_dist;
                pq.push({stops+1,neigh,new_dist});
            }
        }
       }
       return dist[dst]==INT_MAX?-1:dist[dst];


    }
};