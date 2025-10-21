class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int odd = 0, even = 1; // we consider empty prefix sum as even
        int sum = 0, result = 0;

        for (int num : arr) {
            sum += num;

            if (sum % 2 == 0) {
                result = (result + odd) % MOD;
                even++;
            } else {
                result = (result + even) % MOD;
                odd++;
            }
        }

        return result;
    }
};
