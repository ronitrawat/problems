class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> s(nums.begin(),nums.end());
       int longest=0;
       for( int a:s){
        if(s.find(a-1)==s.end()){
            int curr=a;
            int streak=1;


            while(s.find(curr+1)!=s.end()){
                streak++;
                curr++;
            }
            longest=max(longest,streak);
        }
       }
            return longest;
    }
};