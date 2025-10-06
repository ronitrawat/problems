class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      vector<pair<int, int>> a;

       int rows=matrix.size();
       int columns=(matrix[0]).size(); 
       
       for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            if(matrix[i][j]==0){
                a.push_back({i,j});
            }
        }
       }
      for (auto p : a) {
    int x = p.first;
    int y = p.second;
    for(int i=0;i<rows;i++){
        matrix[i][y]=0;
    }
    for(int i=0;i<columns;i++){
        matrix[x][i]=0;
    }
}


    }
};