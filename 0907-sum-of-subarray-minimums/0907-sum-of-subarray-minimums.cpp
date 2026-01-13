class Solution {
public:
    static const int MOD = 1e9 + 7;

    void nextSmaller(vector<int>& arr, vector<int>& nextAns) {
        stack<int> s;
        s.push(-1);
        int n = arr.size();

        for(int i = n-1; i >= 0; i--) {
            while(s.top()!=-1 && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            nextAns.push_back(s.top());
            s.push(i);
        }
    }

    void prevSmaller(vector<int>& arr, vector<int>& prevAns) {
        stack<int> s;
        s.push(-1);
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            while(s.top()!=-1 && arr[s.top()] > arr[i]) {
                s.pop();
            }
            prevAns.push_back(s.top());
            s.push(i);
        }
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nextAns;
        vector<int> prevAns;

        nextSmaller(arr, nextAns);
        reverse(nextAns.begin(), nextAns.end());

        int n = arr.size();
        for(int i = 0; i < n; i++) {
            if(nextAns[i] == -1) nextAns[i] = n;
        }

        prevSmaller(arr, prevAns);

        long long ans = 0;

        for(int i = 0; i < n; i++) {
            int left = i - prevAns[i];
            int right = nextAns[i] - i;
            ans = (ans + (long long)arr[i] * left * right) % MOD;
        }

        return ans;
    }
};
