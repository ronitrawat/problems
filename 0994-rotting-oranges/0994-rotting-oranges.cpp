class Solution {
public:
int row;
int col;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
    

    int orangesRotting(vector<vector<int>>& grid) {
        row=grid.size();
        col=grid[0].size();
        int ans=0;

         queue<pair<int,int>> q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int temp=0;
            int sz=q.size();

            while(sz--){
                auto f=q.front();
                q.pop();

                for(int k=0;k<4;k++){
                   int ii=f.first+dx[k];
                   int jj=f.second+dy[k];

                   if(ii>=0 && jj>=0 && ii<row && jj<col && grid[ii][jj]==1){
                    grid[ii][jj]=2;
                    temp=1;
                    q.push({ii,jj});
                   }

                }

            }
            ans+=temp;

        }
        for(auto v: grid){
            for(int x:v) if(x==1) return -1;
        }

        return ans;
        
    }
};