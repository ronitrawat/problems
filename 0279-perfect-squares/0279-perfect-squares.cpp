class Solution {
public:
    int numSquares(int n) {

        vector<int> sq;

        for(int i=1;i*i<=n;i++)
            sq.push_back(i*i);

        int m = sq.size();
        int INF = 1e9;

        vector<vector<int>> dp(m+1, vector<int>(n+1, INF));

        // Base case
        for(int i=0;i<=m;i++)
            dp[i][0]=0;

        for(int i=1;i<=m;i++){

            for(int j=1;j<=n;j++){

                // Don't take
                dp[i][j]=dp[i-1][j];

                // Take (Unbounded)
                if(sq[i-1]<=j){

                    dp[i][j]=min(dp[i][j],
                                 1+dp[i][j-sq[i-1]]);
                }
            }
        }

        return dp[m][n];
    }
};