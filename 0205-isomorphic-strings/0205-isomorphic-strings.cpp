class Solution {
public:
    string normalize(string st){
        char start ='a';
        string res="";
        unordered_map<char,char> m;
        for(int i=0;i<st.length();i++){
         if(m.find(st[i])==m.end()){
            m[st[i]]=start;
            start++;
         }
        }

        for(int j=0;j<st.length();j++){
           res.push_back(m[st[j]]);
        }
        return res;
    }

    bool isIsomorphic(string s, string t) {
       string str1= normalize(s);
       string str2=normalize(t);
       if(str1.compare(str2)==0){
        return true;
       }
       return false;
    }
};