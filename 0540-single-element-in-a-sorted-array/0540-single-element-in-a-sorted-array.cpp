class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int l=0;
        int h=nums.size()-1;
        while(l<=h){
            int mid =(l+(h-l)/2);
            if(l==h || h-l==1){
                return nums[l];
            }

            if(nums[mid]==nums[mid-1] && mid-1>=0){
             int st=mid-1;
             if(st&1){
                h=st-1;
             }
             else{
                l=mid+1;
             }
            }
              if(nums[mid]==nums[mid+1] && mid+1<=nums.size()-1){
             int st=mid;
             if(st&1){
                h=st-1;
             }
             else{
                l=mid+2;
             }
            }

              if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1] ){
             return nums[mid];
             }
            }


        
        return -1;
        
    }
};