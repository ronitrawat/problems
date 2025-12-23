class Solution {
public:
    bool check(vector<int> &a,int m,int k, int mid ){
        int count =0;
        for (int i=0;i<a.size();i++){
            if(a[i]<=mid){
                count++;}
            if(count==k){
                    m--;
                    count =0;
                    if(m==0){
                    break;
                    }

                }
                if(a[i]>mid){
                    count=0;
                }
            }
         return m==0;
        


    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m>bloomDay.size()){
            return -1;
        }
        if(bloomDay.size()<m*k){
            return -1;
        }
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
         int ans=-1;
         int mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(check(bloomDay,m,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
             low=mid+1;
            }
        }
        return ans;
    }
};