class Solution {
public:
int ans=0;
int row;
int col;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
void dfs(int r,int c,vector<vector<char>> &grid){
   if(r<0 || c<0 || r>=row || c>=col || grid[r][c]!='1'){
    return ;
   }
   grid[r][c]='2';
   for(int i=0;i<4;i++){
   
       int ii=r+dx[i];
       int jj=c+dy[i];
       dfs(ii,jj,grid);
    }
   
   

}
    int numIslands(vector<vector<char>>& grid) {
         row=grid.size();
         col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    ans+=1;
                }
            }
        }
        return ans;
        
    }
};