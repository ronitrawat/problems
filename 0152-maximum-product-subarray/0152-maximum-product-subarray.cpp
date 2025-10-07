class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int prod=INT_MIN;
        int m=INT_MIN;
        for(int i=0;i<n;i++){
            
           
                prod=nums[i];
                m=max(m,prod);
            
            for(int j=i+1;j<n;j++){
                prod=prod*nums[j];
                m=max(m,prod);
            }


        }
        return m;
    }
};