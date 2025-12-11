class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       string res="";
       string  s=strs[0];
       for (int i=0;i<s.length();i++){
        char c=s[i];
        bool put=true;
        for(int j=0;j<strs.size();j++)
       { string a=strs[j];
        if(a[i]!=c){
            put=false;
            break;
        }


       }if(put){
       res.push_back(c);}
       else{break;}
    }return res;
    }
};