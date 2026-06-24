class Solution {
public:

    int solve(vector<int>& coins, int amount, vector<int>& dp) {

        // Base Cases
        if (amount == 0) {
            return 0;
        }

        if (amount < 0) {
            return INT_MAX;
        }

        // Already computed
        if (dp[amount] != -1) {
            return dp[amount];
        }

        int minCoin = INT_MAX;

        for (int i = 0; i < coins.size(); i++) {

            int coin = coins[i];

            if (coin <= amount) {

                int recAns = solve(coins, amount - coin, dp);

                // Valid answer
                if (recAns != INT_MAX) {

                    int coinUsed = 1 + recAns;

                    minCoin = min(minCoin, coinUsed);
                }
            }
        }

        dp[amount] = minCoin;
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, -1);

        int ans = solve(coins, amount, dp);

        return (ans == INT_MAX) ? -1 : ans;
    }
};