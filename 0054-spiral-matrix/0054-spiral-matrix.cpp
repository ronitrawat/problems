class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};            // no rows
        if (matrix[0].empty()) return {};         // first row empty (also protects all rows if ragged)
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        int startr = 0, startc = 0;
        int endr = rows - 1, endc = cols - 1;

        vector<int> mat;
        mat.reserve(rows * cols);

        while (startr <= endr && startc <= endc) {
            for (int i = startc; i <= endc; i++)
                mat.push_back(matrix[startr][i]);
            startr++;

            for (int i = startr; i <= endr; i++)
                mat.push_back(matrix[i][endc]);
            endc--;

            if (startr <= endr) {
                for (int i = endc; i >= startc; i--)
                    mat.push_back(matrix[endr][i]);
                endr--;
            }

            if (startc <= endc) {
                for (int i = endr; i >= startr; i--)
                    mat.push_back(matrix[i][startc]);
                startc++;
            }
        }

        return mat;
    }
};
