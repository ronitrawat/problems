class Solution {
public:
    
    long long merge(vector<int>& nums, int low, int mid, int high) {
        long long count = 0;

        
        int right = mid + 1;

        for (int i = low; i <= mid; i++) {
            while (right <= high &&
                   (long long)nums[i] > 2LL * nums[right]) {
                right++;
            }

            count += right - (mid + 1);
        }

       
        vector<int> temp;
        int left = low;
        right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }

        return count;
    }

    long long mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high)
            return 0;

        int mid = low + (high - low) / 2;

        long long count = 0;

        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += merge(nums, low, mid, high);

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};