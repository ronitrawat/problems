class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mi=*min_element(nums.begin(),nums.end());
        int ma=*max_element(nums.begin(),nums.end());
        vector<int> ans;
        unordered_set<int> a(nums.begin(),nums.end());
        for(int i=mi;i<=ma;i++){
            if(a.find(i)==a.end()){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};