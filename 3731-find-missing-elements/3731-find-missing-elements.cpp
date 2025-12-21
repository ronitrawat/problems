class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mi=*min_element(nums.begin(),nums.end());
        int ma=*max_element(nums.begin(),nums.end());
        vector<int> ans;
        for(int i=mi;i<=ma;i++){
            if(find(nums.begin(),nums.end(),i)==nums.end()){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};