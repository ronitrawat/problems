class Solution {
public:

    vector<vector<int>> dp;

    int solve(int i,int diff,vector<int>& rods){

        if(i==rods.size()){

            if(diff==0)
                return 0;

            return -1000000000;
        }

        if(dp[i][diff]!=-1)
            return dp[i][diff];

        int notTake=solve(i+1,diff,rods);

        int taller=solve(i+1,diff+rods[i],rods);

        int shorter=min(diff,rods[i])+
                    solve(i+1,abs(diff-rods[i]),rods);

        return dp[i][diff]=max({notTake,taller,shorter});
    }

    int tallestBillboard(vector<int>& rods) {

        int sum=0;

        for(int x:rods)
            sum+=x;

        dp.assign(rods.size(),vector<int>(sum+1,-1));

        return solve(0,0,rods);

    }
};