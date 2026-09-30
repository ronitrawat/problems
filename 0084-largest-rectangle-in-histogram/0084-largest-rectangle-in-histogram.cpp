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

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextsmall(heights.size());
        vector<int> prevsmall(heights.size());

        findnextsmall(nextsmall,heights);
        findprevsmall(prevsmall,heights);

         for(int i=0;i<nextsmall.size();i++){
            if(nextsmall[i]==-1){
                nextsmall[i]=nextsmall.size();
            }
        }

         int minAns=INT_MIN;
        for(int i=0;i<heights.size();i++){
            minAns = max(minAns,heights[i]*(nextsmall[i]-prevsmall[i]-1)) ;
        }
        return minAns;
    }
};