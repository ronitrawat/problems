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


    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        dsu d(n);


        vector<vector<int>> edge;
        for(int i=0;i<isConnected.size();i++){
            for(int j=i+1;j<isConnected.size();j++){

                if(isConnected[i][j]==1){
                    d.union_rank(i,j);
                }
            }
        }
        int provinces=0;
        for(int i=0;i<n;i++){
            if(d.find(i)==i){
                provinces++;
            }
        }
        return provinces;
    }
};