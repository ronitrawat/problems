class Solution {
public:
    bool isPalindrome(int x) {
if(x<0 || x%10==0 && x!=0)
    {
        return false;
    }
    else{
         long int rest=x;
         long int remaining=0;
        while(rest>0){
            remaining=remaining*10+rest%10;
            rest=rest/10;}
           if(remaining==x){
            return true;
           }
           else{
            return false;
           }

    }

    }
};