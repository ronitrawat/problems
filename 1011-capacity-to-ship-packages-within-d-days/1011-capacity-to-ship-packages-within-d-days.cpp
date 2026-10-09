class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        int m=weights[0];
        
        for(auto it:weights){
            sum+=it;
            m=max(it,m);
        }
        int ans=INT_MAX;
        int low=m;
        int high=sum;

        while(low<=high){
            int mid=(low+high)/2;
            int k=1;
            int w=0;
            for(auto it: weights){
           
              if(w+it>mid){
                k++;
                w=it;}
            else{
            w+=it;
            }}

            if(k>days){
                low=mid+1;
            }
            else {
               ans=min(ans,mid);
               high=mid-1;
            }


        }
        return ans;
    }
};