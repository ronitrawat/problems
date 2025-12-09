class Solution {
public:
  bool check(vector<int>& piles, int h, int mid){
    double target = 0;  

    for(int x : piles){
        target += ceil((double)x / mid);  
    }

    return target <= h;
}

   
    int minEatingSpeed(vector<int>& piles, int h) {
      int mid=0;
        int low=0;
        int high  =*(max_element(piles.begin(),piles.end()));
       if(h<piles.size()){
        return -1;
       }
        int ans=0;

        while(low<=high){

            mid=low+(high-low)/2;

            if (check(piles,h,mid)){
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