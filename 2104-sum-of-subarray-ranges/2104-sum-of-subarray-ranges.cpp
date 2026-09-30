class Solution {
public:
void findnextsmall(vector<int> &nextsmall,vector<int> arr){
     stack<int> st;
     st.push(-1);
     for(int i=nextsmall.size()-1;i>=0;i--){
        while(st.top()!=-1 && arr[i]<arr[st.top()] ){
            st.pop();
        }
        nextsmall[i]=st.top();
        st.push(i);
     }
    }
    void findprevsmall(vector<int> &prevsmall,vector<int> arr){
       stack<int> st;
     st.push(-1);
     for(int i=0;i<prevsmall.size();i++){
        while(st.top()!=-1 && arr[i]<=arr[st.top()] ){
            st.pop();
        }
        prevsmall[i]=st.top();
        st.push(i);
     }
    }
     void findnextgreat(vector<int> &nextgreat,vector<int> arr){
     stack<int> st;
     st.push(-1);
     for(int i=nextgreat.size()-1;i>=0;i--){
        while(st.top()!=-1 && arr[i]>arr[st.top()] ){
            st.pop();
        }
        nextgreat[i]=st.top();
        st.push(i);
     }
    }
    void findprevgreat(vector<int> &prevgreat,vector<int> arr){
       stack<int> st;
     st.push(-1);
     for(int i=0;i<prevgreat.size();i++){
        while(st.top()!=-1 && arr[i]>=arr[st.top()] ){
            st.pop();
        }
        prevgreat[i]=st.top();
        st.push(i);
     }
    }
    long long subArrayRanges(vector<int>& nums) {
        vector<int> nextgreat(nums.size());
        vector<int> prevgreat(nums.size());
        vector<int> nextsmall(nums.size());
        vector<int> prevsmall(nums.size());

        findnextsmall(nextsmall,nums);
        findprevsmall(prevsmall,nums);
        findprevgreat(prevgreat,nums);
        findnextgreat(nextgreat,nums);
        for(int i=0;i<nextsmall.size();i++){
            if(nextsmall[i]==-1){
                nextsmall[i]=nextsmall.size();
            }
        }
        for(int i=0;i<nextgreat.size();i++){
            if(nextgreat[i]==-1){
                nextgreat[i]=nextgreat.size();
            }
        }
        long long int maxAns=0;
        for(int i=0;i<nums.size();i++){
            int left=i-prevgreat[i];
            int right=nextgreat[i]-i;

            const int MOD = 1e9 + 7;

            maxAns = (maxAns + (long long)nums[i] * left * right) ;
        }
        long long int minAns=0;
        for(int i=0;i<nums.size();i++){
            int left=i-prevsmall[i];
            int right=nextsmall[i]-i;

            const int MOD = 1e9 + 7;

            minAns = (minAns + (long long)nums[i] * left * right) ;
        }
        return maxAns-minAns;
    }
};