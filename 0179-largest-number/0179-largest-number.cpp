class Solution {
public:
    static bool check(const string &a, const string &b) {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> a(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            a[i] = to_string(nums[i]);
        }

        sort(a.begin(), a.end(), check);

        if (a[0] == "0") return "0";

        string ans = "";
        for (int i = 0; i < a.size(); i++) {
            ans += a[i];
        }

        return ans;
    }
};
