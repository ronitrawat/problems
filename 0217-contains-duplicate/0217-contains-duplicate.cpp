class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
     unordered_set<int> res;
        for(int i:nums){

            
            if(res.count(i)){
                return true;
            }
            res.insert(i);
        }
        return false;
    }
};