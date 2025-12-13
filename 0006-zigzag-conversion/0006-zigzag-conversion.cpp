class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> ans(numRows);
        int i = 0, n = s.size();

        while (i < n) {

          
            for (int row = 0; row < numRows && i < n; row++) {
                ans[row].push_back(s[i]);
                i++;
            }

            
            for (int row = numRows - 2; row >= 1 && i < n; row--) {
                ans[row].push_back(s[i]);
                i++;
            }
        }

        string res = "";
        for (string &r : ans) res += r;
        return res;
    }
};
