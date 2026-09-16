class Solution {
public:
    int r;
    int c;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    void dfs(int i,int j, int org,int color,vector<vector<int>> &image){
        if(i<0 || j<0 || i>=r || j>=c || image[i][j]!=org){
            return ;
        }
        image[i][j]=color;

        for(int k=0;k<4;k++){
            int ii=i+dx[k];
            int jj=j+dy[k];

            dfs(ii,jj,org,color,image);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        r=image.size();
        c=image[0].size();

        int org=image[sr][sc];

        if(image[sr][sc]==color){
            return image;
        }

        dfs(sr,sc,org,color,image);

        return image;
    }
};