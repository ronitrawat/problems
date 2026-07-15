class Solution {
public:

    unordered_map<string,bool> dp;

    bool solve(string s1, string s2){

        if(s1 == s2)
            return true;

        if(s1.length() != s2.length())
            return false;

        if(s1.length() <= 1)
            return false;

        string key = s1 + " " + s2;

        if(dp.count(key))
            return dp[key];

        int n = s1.length();

        for(int k = 1; k < n; k++){

            bool swap =
                solve(s1.substr(0,k), s2.substr(n-k))
                &&
                solve(s1.substr(k), s2.substr(0,n-k));

            bool noswap =
                solve(s1.substr(0,k), s2.substr(0,k))
                &&
                solve(s1.substr(k), s2.substr(k));

            if(swap || noswap)
                return dp[key] = true;
        }

        return dp[key] = false;
    }

    bool isScramble(string s1, string s2) {

        dp.clear();

        return solve(s1,s2);
    }
};