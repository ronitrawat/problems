class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int count=0;
        for(auto it:nums){
           if(it==0){
            count=0;
           }
           else{
            count++;
            ans=max(count,ans);
           }
        }
        return ans;
    }
};