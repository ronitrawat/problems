class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1=INT_MIN;
        int ele2=INT_MIN;
        int cnt1=0;
        int cnt2=0;


        for(auto n: nums){
            if(n==ele1){
                cnt1++;

            }
            else if(n==ele2){
                cnt2++;
            }
            else if(cnt1==0 && n!=ele1){
                ele1=n;
                cnt1++;
            }
            else if(cnt2==0 && n!=ele2){
                ele2=n;
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        vector<int>ans;
        int n=nums.size()/3+1;
        cnt1=0;
        cnt2=0;
        for(int it:nums){
         if(it==ele1){
            cnt1++;
            
         }
         if(it==ele2){
            cnt2++;
         }
        }
        if(cnt1>=n){
            ans.push_back(ele1);

        }
        if(cnt2>=n){
            ans.push_back(ele2);
        }
        return ans;
    }
};