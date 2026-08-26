class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int mid=0;
        int high =nums.size()-1;
        for(int i=0;i<nums.size();i++){
            if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
                
            }
        }
        
    }
};