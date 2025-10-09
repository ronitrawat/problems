class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=n-2;i>=0;i--){
            
            if(nums[i]<nums[i+1]){
                int m=INT_MAX;
                int idx;
              for (int j=i+1;j<nums.size();j++){
                if(nums[j]>nums[i] && nums[j]<m){
                    m=nums[j];
                    idx=j;
                }
              }

                count++;
                swap(nums[i],nums[idx]);
                sort(nums.begin()+i+1,nums.end());
                goto end;
                               
                          }

        }
        end:
          if(!count){
            sort(nums.begin(),nums.end());
          }   

    }
};