class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
     map<int,int> res;
        for(int i:nums){

            res[i]++;
            if(res[i]>1){
                return true;
            }
        }
        return false;
    }
};