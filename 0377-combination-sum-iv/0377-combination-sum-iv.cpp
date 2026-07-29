class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {

        int maxLen = target; // smallest number can be 1

        vector<vector<unsigned int>> dp(maxLen + 1,
                                        vector<unsigned int>(target + 1, 0));

        dp[0][0] = 1;

        for (int len = 1; len <= maxLen; len++) {

            for (int sum = 1; sum <= target; sum++) {

                for (int num : nums) {

                    if (num <= sum)
                        dp[len][sum] += dp[len - 1][sum - num];
                }
            }
        }

        unsigned int ans = 0;

        for (int len = 1; len <= maxLen; len++)
            ans += dp[len][target];

        return ans;
    }
};