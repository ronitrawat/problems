class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
         
         int dx[4]={-1,1,0,0};
         int dy[4]={0,0,1,-1};

        int row=heights.size();
        int col=heights[0].size();

        priority_queue<vector<int>,vector<vector<int>> ,greater<vector<int>>> pq;
        vector<vector<int>> dist(row,vector<int>(col,INT_MAX));

        pq.push({0,0,0});
        dist[0][0]=0;

        while(!pq.empty()){
            auto pr=pq.top();
            pq.pop();
            int disp=pr[0];
            int x=pr[1];
            int y=pr[2];

            for(int k=0;k<4;k++){
                int ii=x+dx[k];
                int jj=y+dy[k];

                if(ii<0 || jj<0 || ii>=row || jj>=col){
                    continue;
                }
                int new_dist=max(disp,abs(heights[x][y]-heights[ii][jj]));
                if(new_dist<dist[ii][jj]){
                    dist[ii][jj]=new_dist;
                    pq.push({dist[ii][jj],ii,jj});
                }
            }
        }
        return dist[row-1][col-1];
    }
};