class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> a(nums1.begin(),nums1.end());
        set<int> b(nums2.begin(),nums2.end());
        
        vector<vector<int>> ans;
        vector<int> c;
        vector<int> d;
       bool flag1=false;
       bool flag2=false;
        for(auto &i:a){
            if(b.find(i)==b.end()){
                flag1=true;
                c.push_back(i);
            }
        }

        for(auto &i:b){
            if(a.find(i)==a.end()){
                flag1=true;
                d.push_back(i);
            }
        }
       ans.push_back(c);
       ans.push_back(d);
     return ans;
    }
};