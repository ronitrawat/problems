class Solution {
public:
    void findnext(vector<int> &next,vector<int> arr){
     stack<int> st;
     st.push(-1);
     for(int i=next.size()-1;i>=0;i--){
        while(st.top()!=-1 && arr[i]<arr[st.top()] ){
            st.pop();
        }
        next[i]=st.top();
        st.push(i);
     }
    }
    void findprev(vector<int> &prev,vector<int> arr){
       stack<int> st;
     st.push(-1);
     for(int i=0;i<prev.size();i++){
        while(st.top()!=-1 && arr[i]<=arr[st.top()] ){
            st.pop();
        }
        prev[i]=st.top();
        st.push(i);
     }
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> next(arr.size());
        vector<int> prev(arr.size());

        findnext(next,arr);
        findprev(prev,arr);
        for(int i=0;i<next.size();i++){
            if(next[i]==-1){
                next[i]=next.size();
            }
        }
        long long int ans=0;
        for(int i=0;i<arr.size();i++){
            int left=i-prev[i];
            int right=next[i]-i;

            const int MOD = 1e9 + 7;

            ans = (ans + (long long)arr[i] * left * right) % MOD;
        }

        return ans;
    }
};