class Solution {
public:
    vector<vector<int>> dp;

    int solve(int eggs, int floors){

        // Base Cases
        if(floors == 0 || floors == 1)
            return floors;

        if(eggs == 1)
            return floors;

        if(dp[eggs][floors] != -1)
            return dp[eggs][floors];

        int low = 1;
        int high = floors;
        int ans = INT_MAX;

        while(low <= high){

            int mid = low + (high - low) / 2;

            int breakCase, surviveCase;

            // Egg Breaks
            if(dp[eggs-1][mid-1] != -1)
                breakCase = dp[eggs-1][mid-1];
            else
                breakCase = solve(eggs-1, mid-1);

            // Egg Survives
            if(dp[eggs][floors-mid] != -1)
                surviveCase = dp[eggs][floors-mid];
            else
                surviveCase = solve(eggs, floors-mid);

            int temp = 1 + max(breakCase, surviveCase);

            ans = min(ans, temp);

            // Binary Search
            if(breakCase < surviveCase)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return dp[eggs][floors] = ans;
    }
    int superEggDrop(int k, int n) {
      dp.assign(k + 1, vector<int>(n + 1, -1));

        return solve(k, n);   
    }
};