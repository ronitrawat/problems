class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> n;
        int ans = 0;
        int i = 0;

        while (i < chars.size()) {
            int j = i;
            char d = chars[i];
            int l = 0;

            while (j < chars.size() && d == chars[j]) {
                l++;
                j++;
            }

            if (l == 1) {
                ans += 1;
                n.push_back(chars[i]);
            } 
            else {
                ans += 1;  
                n.push_back(chars[i]);  // push the character

                string num = to_string(l);
                ans += num.length();

                for (char c : num) {
                    n.push_back(c);
                }
            }

            i = j;
        }

        chars = n;  
        return ans;
    }
};
