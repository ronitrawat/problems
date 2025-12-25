class Solution {
public:
bool check(string s ,int low,int high){
    while(low<=high){
        if(s[low]==s[high]){
            low++;
            high--;
        }
        else{
            return false;
        }
    }
    return true;
}
    bool validPalindrome(string s) {
       int low=0;
       int high =s.length()-1;
       int count=1;

       while(low<=high){
       if(s[low]==s[high]){
        low++;
        high--;
       }
       else if( s[low]!=s[high] ){
       bool res= check(s,low+1,high) || check(s,low,high-1);
       if(res){
        return true;
       }
       else{return false;}
       }

       
    }return true; }
};