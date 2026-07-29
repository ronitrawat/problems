class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<vector<int>>> dp(group.size()+1,vector<vector<int>>(n+1,vector<int>(minProfit+1,0)));

        dp[0][0][0]=1;
        int MOD=1e9+7;

        for(int i=1;i<=group.size();i++){

            int members=group[i-1];
            int pro=profit[i-1];

            for(int j=0;j<=n;j++){
                for(int k=0;k<=minProfit;k++){
                    dp[i][j][k]=dp[i-1][j][k];

                    if(j>=members){
                        dp[i][j][k]=(dp[i][j][k]+dp[i-1][j-members][max(0,k-pro)])% MOD;
                    }
                }
            }
        }
        int ans=0;
        for(int j=0;j<=n;j++){
           ans=(ans+dp[group.size()][j][minProfit])%MOD;
        }    
        return ans;}
};