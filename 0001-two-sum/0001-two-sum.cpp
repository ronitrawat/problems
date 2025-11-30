class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> array;
        for(int i =0;i<nums.size();i++){
           int rem=target-nums[i];
           if(array.find(rem)!=array.end()){
            return {i,array[rem]};
           }
           array[nums[i]]=i;
        }

        return {-1};
        
    }
};