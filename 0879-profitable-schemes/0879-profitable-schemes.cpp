class Solution {
public:
    int profitableSchemes(int n, int minProfit,
                          vector<int>& group,
                          vector<int>& profit) {

        const int MOD = 1e9 + 7;

        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));

        dp[0][0] = 1;

        for (int i = 0; i < group.size(); i++) {

            int members = group[i];
            int earn = profit[i];

            // Backward because each crime can be chosen only once
            for (int j = n; j >= members; j--) {

                for (int k = minProfit; k >= 0; k--) {

                    int newProfit = min(minProfit, k + earn);

                    dp[j][newProfit] =
                        (dp[j][newProfit] +
                         dp[j - members][k]) % MOD;
                }
            }
        }

        int ans = 0;

        for (int j = 0; j <= n; j++) {
            ans = (ans + dp[j][minProfit]) % MOD;
        }

        return ans;
    }
};