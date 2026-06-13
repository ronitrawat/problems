class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        priority_queue<int> q;
        long long int sum=0;
        int n=nums.size();
        vector<long long> left;
        for(int i=0;i<n;i++){
            q.push(nums[i]);
            sum+=nums[i];
            if(q.size()>n/3){
                int r=q.top();
                q.pop();
                sum-=r;
            }
            left.push_back(sum);
        }

        priority_queue<int,vector<int>,greater<int>> q2;
        long long int  nsum=0;
        long long right[n];


        for(int i=n-1;i>=0;i--){
            q2.push(nums[i]);
            nsum+=nums[i];
            if(q2.size()>n/3){
                int r=q2.top();
                q2.pop();
                nsum-=r;
            }
            right[i]=nsum;
        }

        long long int ans =LLONG_MAX;
        for(int i=n/3-1;i<2*n/3;i++){
           ans=min(ans,left[i]-right[i+1]);
        }
        return ans;
    }
};