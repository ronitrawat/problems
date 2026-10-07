class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int m=piles[0];
        for(int i=1;i<piles.size();i++){
            m=max(m,piles[i]);
        }
        int low=1;
        int high=m;
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            long long int count=0;
            for(int i=0;i<piles.size();i++){
               
                    count+=ceil(double(piles[i])/mid);
                    
                
            }
            
            if(count<=h){
            ans=min(ans,mid);
            high=mid-1;}
            
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};