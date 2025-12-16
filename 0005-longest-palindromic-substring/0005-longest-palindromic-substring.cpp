class Solution {

string expand(string s,int i, int j){
    int m=-1;
    int a=-1;

    while(i>=0 && j<s.length() && s[i]==s[j]){
      int ans =j-i+1;
      if(ans>a){
       a=ans;
     m=i;
      
      i--;
      j++;
    }
} 
if (m == -1) return "";
string n=s.substr(m,a);
return n;
}

public:
    string longestPalindrome(string s) {
       string best;
        for (int center=0 ;center<s.length();center++){
            int i=center;
            int j=center;
            string odd=expand(s,i,j);
            int a=center ;
            int b=center+1;
            
            string even =expand(s,a,b);
            if (odd.length() >= even.length()) {
                if (odd.length() > best.length()) best = odd;
            } else {
                if (even.length() > best.length()) best = even;
            }
        }
        return best;
         }
      
};