class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1,j=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[j]){
                
            }
            else{
                j++;
                nums[j]=nums[i];

            }
        }
       return j+1; 
    }
};