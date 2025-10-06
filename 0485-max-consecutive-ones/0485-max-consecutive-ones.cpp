class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int m=-1;
        if(nums.size()==1){
            if(nums[0]==1){
                count++;
                return count;
            }
        }
        for (int i=0;i<nums.size()-1;i++){
            if(nums[i]==1 && nums[i+1]==1){
                count++;
                m=max(m,count);}
                else if(nums[i]==1 && nums[i+1]!=1){
                    count=0;
                    m=max(m,count);
                }
                else if(nums[nums.size()-1]==1){
                    count=0;
                   m=max(m,count);
                }
                
            
        }
        return m+1;
    }
};