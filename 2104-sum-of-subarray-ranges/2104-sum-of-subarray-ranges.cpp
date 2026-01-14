class Solution {
public:
    void nextSmaller(vector<int>& nums, vector<int>& nextSmall) {
        stack<int> s;
        s.push(-1);
        int n = nums.size();

        for (int i = n-1; i >= 0; i--) {
            while (s.top()!=-1 && nums[s.top()] >= nums[i]) {
                s.pop();
            }
            nextSmall[i] = s.top();
            s.push(i);
        }
    }

    void prevSmaller(vector<int>& nums, vector<int>& prevSmall) {
        stack<int> s;
        s.push(-1);

        for (int i = 0; i < nums.size(); i++) {
            while (s.top()!=-1 && nums[s.top()] > nums[i]) {
                s.pop();
            }
            prevSmall[i] = s.top();
            s.push(i);
        }
    }

    void nextGreater(vector<int>& nums, vector<int>& nextGreat) {
        stack<int> s;
        s.push(-1);
        int n = nums.size();

        for (int i = n-1; i >= 0; i--) {
            while (s.top()!=-1 && nums[s.top()] <= nums[i]) {
                s.pop();
            }
            nextGreat[i] = s.top();
            s.push(i);
        }
    }

    void prevGreater(vector<int>& nums, vector<int>& prevGreat) {
        stack<int> s;
        s.push(-1);

        for (int i = 0; i < nums.size(); i++) {
            while (s.top()!=-1 && nums[s.top()] < nums[i]) {
                s.pop();
            }
            prevGreat[i] = s.top();
            s.push(i);
        }
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> nextSmall(n), prevSmall(n), nextGreat(n), prevGreat(n);

        nextSmaller(nums, nextSmall);
        prevSmaller(nums, prevSmall);
        nextGreater(nums, nextGreat);
        prevGreater(nums, prevGreat);

        for (int i = 0; i < n; i++) {
            if (nextSmall[i] == -1) nextSmall[i] = n;
            if (nextGreat[i] == -1) nextGreat[i] = n;
        }

        long long minSum = 0, maxSum = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - prevSmall[i];
            long long right = nextSmall[i] - i;
            minSum += nums[i] * left * right;
        }

        for (int i = 0; i < n; i++) {
            long long left = i - prevGreat[i];
            long long right = nextGreat[i] - i;
            maxSum += nums[i] * left * right;
        }

        return maxSum - minSum;
    }
};
