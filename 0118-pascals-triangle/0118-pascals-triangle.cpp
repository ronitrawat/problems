class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> p;

        for(int i=0;i<numRows;i++){
            vector<int> row(i+1,1);
            

            for(int j=1;j<i;j++){
                row[j]=p[i-1][j]+p[i-1][j-1];


            }
            p.push_back(row);
        }

        return p;

    }
};