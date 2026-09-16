class Solution {
public:
    int r;
    int c;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    void bfs(int i,int j, int org,int color,vector<vector<int>> &image){
        queue<pair<int,int>> q;
        q.push({i,j});
        image[i][j]=color;

        while(!q.empty()){
            auto f=q.front();
            q.pop();
            int m=f.first;
            int n=f.second;
            for(int k=0;k<4;k++){
                int ii=m+dx[k];
                int jj=n+dy[k];
                if(ii<0 || jj<0 || ii>=r || jj >=c || image[ii][jj]!=org){
                    continue;
                }
                q.push({ii,jj});
                image[ii][jj]=color;
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        r=image.size();
        c=image[0].size();

        int org=image[sr][sc];

        if(image[sr][sc]==color){
            return image;
        }

        bfs(sr,sc,org,color,image);

        return image;
    }
};