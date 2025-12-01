

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long count = 0;
        int l=0;
        int r=0;
        int j=0;
    
    for (int i=0;i<nums.size();i++){
        if(i==0){
            count++;
            l=nums[i]-2;
            r=nums[i]+2;

        }
        else if(nums[i]>=l && nums[i]<=r){
            l=max(l,nums[i]-2);
            r=min(r,nums[i]+2);
            count+=i-j+1;
        }
        else{
            l=nums[i]-2;
            r=nums[i]+2;
            j=i-1;
            while(nums[j]>=nums[i]-2 && nums[j]<=nums[i]+2){
                 l=max(l,nums[j]-2);
            r=min(r,nums[j]+2);
            j--;

            }j++;
            count+=i-j+1;
        }



    }
    return count;
    }

    
};
