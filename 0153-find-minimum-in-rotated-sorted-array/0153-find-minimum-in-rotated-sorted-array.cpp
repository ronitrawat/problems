class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                // Minimum must be to the right of mid
                left = mid + 1;
            } else {
                // Minimum is at mid or to the left of mid
                right = mid;
            }
        }

        return nums[left];  // or nums[right], since left == right
    }
};
