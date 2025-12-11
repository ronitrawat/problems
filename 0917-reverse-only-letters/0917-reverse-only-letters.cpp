class Solution {
public:
    string reverseOnlyLetters(string s) {
       int i=0;
       int j=s.length()-1;
      while(i<=j){
        if((isalpha(s[i]))!=0 && isalpha(s[j])!=0){
            swap(s[i],s[j]);
            i++;
            j--;

        }
        else if(isalpha(s[i])==0 && isalpha(s[j])!=0 )
        {
            i++;
        }
        else if(isalpha(s[i])!=0 && isalpha(s[j])==0 )
        {
            j--;
        }
        else{
            i++;
            j--;
        }
      }
      return s; 
    }
};