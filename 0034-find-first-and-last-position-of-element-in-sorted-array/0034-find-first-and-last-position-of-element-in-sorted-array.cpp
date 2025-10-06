class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        if(nums.size()==0){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
       int count=0;
       int a;
        for(int i=0;i<nums.size();i++){
          if(nums[i]==target){
            count++;
            if(count==1){
                res.push_back(i);
            }
             a=i;
          }

         
        }
       
    if(count==0){
        res.push_back(-1);
        res.push_back(-1);
    }
    else{
         res.push_back(a);
    }
     return res;
    }
};