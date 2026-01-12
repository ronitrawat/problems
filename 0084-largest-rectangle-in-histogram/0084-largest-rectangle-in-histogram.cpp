class Solution {
public:

void nextSmaller(vector<int>& heights,vector<int>& nextAns){
 int n=heights.size();
    stack<int> s;
    s.push(-1);
    for(int i=n-1;i>=0;i--){
        int element=heights[i];
        while(s.top()!=-1 && heights[s.top()]>=element){
            s.pop();
        }
        nextAns.push_back(s.top());
        s.push(i);
    }
}
void prevSmaller(vector<int>& heights,vector<int>& prevAns){
    int n=heights.size();
    stack<int> s;
    s.push(-1);
    for(int i=0;i<=n-1;i++){
        int element=heights[i];
        while(s.top()!=-1 && heights[s.top()]>=element){
            s.pop();
        }
        prevAns.push_back(s.top());
        s.push(i);


    }
}


    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextAns;
        vector<int> prevAns;
        int n=heights.size();
        nextSmaller(heights,nextAns);
        reverse(nextAns.begin(),nextAns.end());

        


        for(int i=0;i<n;i++){
            if(nextAns[i]==-1){
                nextAns[i]=n;
            }
        }
        prevSmaller(heights,prevAns);

        int maxArea=INT_MIN;
        for(int i=0;i<n;i++){
            int width=nextAns[i]-prevAns[i]-1;
            int height=heights[i];
            int currArea=height*width;
            maxArea=max(maxArea,currArea);
        }
        return maxArea;

    }
};