class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0;
        for(int i=0;i<stones.size();i++){
           sum+=stones[i];        }
        int s1=sum/2;
vector<bool> dp(s1+1);
dp[0]=true;
        for(int j=1;j<=s1;j++){
            dp[j]=false;}
           for(int i=1;i<=stones.size();i++){
            for(int j=s1;j>=stones[i-1];j--){
                dp[j]=dp[j] || dp[j-stones[i-1]];
            }}
        int best=0;
        for(int j=s1;j>=0;j--){
            if(dp[j]){
                best=j;
                break;
            }
        }
        return sum-2*best;


    }
};