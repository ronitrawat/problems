class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int result=INT_MAX;
        for(int i=0;i<n;i++){
            result=min(result,nums[i]);
        }
        return result;
    }
};