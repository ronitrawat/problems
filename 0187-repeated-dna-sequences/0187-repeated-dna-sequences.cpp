class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        int n = s.size();

        if(n < 10)
            return {};

        unordered_map<char,int> mp = {
            {'A',0},
            {'C',1},
            {'G',2},
            {'T',3}
        };

        unordered_set<int> seen;
        unordered_set<int> repeated;

        vector<string> ans;

        int hash = 0;

        // Build first window of length 10
        for(int i=0;i<10;i++) {
            hash <<= 2;
            hash |= mp[s[i]];
        }

        seen.insert(hash);

        // Mask keeps only last 20 bits
        int mask = (1 << 20) - 1;

        for(int i=10;i<n;i++) {

            hash <<= 2;

            hash |= mp[s[i]];

            hash &= mask;

            if(seen.count(hash)) {

                if(!repeated.count(hash)) {

                    ans.push_back(
                        s.substr(i - 9, 10)
                    );

                    repeated.insert(hash);
                }
            }
            else {
                seen.insert(hash);
            }
        }

        return ans;
    }
};