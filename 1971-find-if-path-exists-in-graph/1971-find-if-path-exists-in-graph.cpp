

class Solution {
public:
    class dsu{
        private:
             vector<int> parent;
             vector<int> rank;

        public:
             dsu(int n){
                parent.resize(n);
                rank.resize(n,1);
                for(int i=0;i<n;i++){
                    parent[i]=i;
                }
             }

             int find(int node){
                if(parent[node]==node){
                    return node;
                }
                return parent[node]=find(parent[node]);
             }


             void union_rank(int a,int b){
                int leader_a=find(a);
                int leader_b=find(b);

                if(leader_a!=leader_b){
                    if(rank[leader_b]<rank[leader_a]){
                        parent[leader_b]=leader_a;
                        rank[leader_a]+=rank[leader_b];
                    }
                    else{
                        parent[leader_a]=leader_b;
                        rank[leader_b]+=rank[leader_a];
                    }
                }
             }
    };

    

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        dsu d(n);

        for(int i=0;i<edges.size();i++){
            int a =edges[i][0];
            int b=edges[i][1];

           d.union_rank(a,b);

        }
        

        return d.find(source)==d.find(destination);
    }
};