class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> item;
        for (int i = 0; i < n ; i++) {
           if(item.count(nums[i])){
              if(i-item[nums[i]]<=k){
                return true;}

           }
           item[nums[i]]=i;

        }
        return false;
    }
};
