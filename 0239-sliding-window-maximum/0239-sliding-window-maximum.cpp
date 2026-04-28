class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> q;
    vector<int> ans;

    for(int i=0;i<k;i++){
        while(!q.empty() && nums[i]>nums[q.back()]){
            q.pop_back();
        }
        
            q.push_back(i);
        
    }
    int id=q.front();
    ans.push_back(nums[id]);

    for(int i=k;i<nums.size();i++){
        //removal
        int id=q.front();
        if(!q.empty() && i-id>=k){
            q.pop_front();
        }

       
        //removal
        while(!q.empty() && nums[q.back()]<nums[i]){
            q.pop_back();
        }
        //addition 
        q.push_back(i);
        ans.push_back(nums[q.front()]);


    }
    return ans;
    }


};