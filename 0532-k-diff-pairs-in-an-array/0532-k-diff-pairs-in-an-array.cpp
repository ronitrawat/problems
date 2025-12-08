class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        vector<vector<int >> ans;
    for (int i=0;i<nums.size();i++){
        for (int j=i+1;j<nums.size();j++){
            if(abs(nums[j]-nums[i])==k){
            vector<int> a;
            a.push_back(nums[i]);
            a.push_back(nums[j]);
            sort(a.begin(),a.end());
            ans.push_back(a);
            }
        }
    }


    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    return ans.size();

    }
};