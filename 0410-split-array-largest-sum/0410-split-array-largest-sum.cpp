class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int m=INT_MIN;
        int sum=0;
        for(auto it: nums){
            m=max(it,m);
            sum+=it;

        }
        int low=m;
        int high=sum;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            int splits=1;
            int total=0;

            for(auto it:nums){
              if(total+it<=mid){
                total+=it;
              }
              else{
                splits++;
                total=it;
              }
            }
            if(splits>k){
                low=mid+1;

            }
            else{
                high=mid-1;
                ans=mid;
            }
        }
        return low;
    }
};