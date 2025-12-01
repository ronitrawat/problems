

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long count = 0;
      deque<int> minQ,maxQ;
      int low=0;

      for (int high=0;high<nums.size();high++){

       while (!maxQ.empty() && maxQ.back()<nums[high]){
        maxQ.pop_back();

       }
       maxQ.push_back(nums[high]);

         while (!minQ.empty() && minQ.back()>nums[high]){
        minQ.pop_back();

       }
       minQ.push_back(nums[high]);


       while(maxQ.front()-minQ.front()>2){
        if(nums[low]==minQ.front()){
            minQ.pop_front();
        }
        if(nums[low]==maxQ.front()){
            maxQ.pop_front();
        }
        low++;
       }
count+=high-low+1;
      }
    return count;
    }

    
};
