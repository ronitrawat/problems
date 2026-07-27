class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0;
        for(int i=0;i<stones.size();i++){
           sum+=stones[i];        }
        int s1=sum/2;
vector<vector<bool>> dp(stones.size()+1,vector<bool>(s1+1));
        for(int j=0;j<=s1;j++){
            dp[0][j]=false;}for(int i=0;i<=stones.size();i++){
            dp[i][0]=true;}for(int i=1;i<=stones.size();i++){
            for(int j=1;j<=s1;j++){
                if(stones[i-1]<=j){
                    dp[i][j]=dp[i-1][j-stones[i-1]] || dp[i-1][j];}
                else{
                    dp[i][j]=dp[i-1][j];
                }     }}
        int best=0;
        for(int j=s1;j>=0;j--){
            if(dp[stones.size()][j]){
                best=j;
                break;
            }
        }
        return sum-2*best;


    }
};