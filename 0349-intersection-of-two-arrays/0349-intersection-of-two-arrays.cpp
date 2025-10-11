class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> a(nums1.begin(),nums1.end());
        set<int> b(nums2.begin(),nums2.end());
        vector<int> ans;
        for(int num:a){
              if(b.find(num)!=b.end()){
               ans.push_back(num);
              }
        }
    
    return ans;}

};