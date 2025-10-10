class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        int ans=nums[0];
        int maxcount=0;
        for(auto &i:freq){
            if(i.second>maxcount){
         maxcount=i.second;
         ans=i.first;}
        }


      return ans;

    }
};