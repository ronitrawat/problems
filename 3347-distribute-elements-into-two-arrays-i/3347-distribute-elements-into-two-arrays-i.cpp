class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a;
        vector<int> b;

        // Step 1: Add first two elements
        a.push_back(nums[0]);
        b.push_back(nums[1]);

        // Step 2: Distribute remaining elements
        for (int i = 2; i < nums.size(); i++) {
            if (a.back() > b.back()) {
                a.push_back(nums[i]);
            } else {
                b.push_back(nums[i]);
            }
        }

        // Step 3: Concatenate a and b into result
        vector<int> result = a;
        result.insert(result.end(), b.begin(), b.end());

        return result;
    }
};
