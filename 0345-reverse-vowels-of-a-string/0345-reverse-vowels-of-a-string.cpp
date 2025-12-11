class Solution {
public:
    string reverseVowels(string s) {
         string v = "aeiouAEIOU";
         int i=0;
         int j=s.length()-1;
         while(i<=j){
           
            if(v.find(s[i])!=-1 && v.find(s[j])!=-1){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(v.find(s[i])!=-1 && v.find(s[j])==-1){
              
                j--;
            }
           else if(v.find(s[i])==-1 && v.find(s[j])!=-1){
                i++;
                
            }
            else{
                i++;
                j--;
            }

         }
         return s;


    }
};