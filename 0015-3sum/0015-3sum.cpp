class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {

            if(i > 0 && nums[i] == nums[i - 1]) continue;  // skip duplicate i

            int target = -nums[i];
            int low = i + 1;
            int high = nums.size() - 1;

            while(low < high) {
                int sum = nums[low] + nums[high];

                if(sum == target) {
                    ans.push_back({nums[i], nums[low], nums[high]});
                    low++;
                    high--;

                    // skip duplicates for low
                    while(low < high && nums[low] == nums[low - 1]) low++;

                    // skip duplicates for high
                    while(low < high && nums[high] == nums[high + 1]) high--;

                }
                else if(sum > target) {
                    high--;
                }
                else {
                    low++;
                }
            }
        }
        return ans;
    }
};
