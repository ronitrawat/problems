class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct=1;
        int minProduct=1;
        int ans=INT_MIN;
        for(int n:nums){
            if(n<0){
                swap(maxProduct,minProduct);
            }
            maxProduct=max(n,maxProduct*n);
            minProduct=min(n,minProduct*n);
        ans=max(maxProduct,ans);

        }
        return ans;
    }
};