class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        int start=0;
        int end=0;
        int bestRange=INT_MAX;
        int maxVal=INT_MIN;
        int minVal=INT_MAX;
        for(int i=0;i<nums.size();i++){
            q.push({nums[i][0],i,0});
            maxVal=max(maxVal,nums[i][0]);
        }
        while(!q.empty()){
            auto it=q.top();
            q.pop();

            minVal=it[0];
            int row=it[1];
            int col=it[2];


            if(maxVal - minVal < bestRange)
         {
            bestRange = maxVal - minVal;
            start = minVal;
            end = maxVal;
            }
            if(col+1==nums[row].size()){
                break;
            }
            maxVal=max(maxVal,nums[row][col+1]);
            q.push({nums[row][col+1],row,col+1});
        

        }
        return {start,end};


    }
};