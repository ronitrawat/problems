#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // Rotate nums starting at index i
            rotate(nums.begin(), nums.begin() + 1, nums.end());

            // Check if rotated array is sorted
            if (is_sorted(nums.begin(), nums.end())) {
                return true;
            }
        }

        return false;
    }
};
