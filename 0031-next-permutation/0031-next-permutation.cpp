class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int dec = -1;

        for(int i = nums.size() - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                dec = i;
                break;
            }
        }

        if(dec == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int nextpt = -1;

        for(int i = nums.size() - 1; i > dec; i--) {
            if(nums[i] > nums[dec]) {
                nextpt = i;
                break;
            }
        }

        swap(nums[dec], nums[nextpt]);

        reverse(nums.begin() + dec + 1, nums.end());
    }
};