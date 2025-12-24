class Solution {
public:
   string normalize(string s){
    char start='a';
    string n="";
    unordered_map<char,char> a;
    for(auto p: s){
        if(a.find(p)!=a.end()){
            n+=a[p];
        }
        else{
            start++;
            a[p]=start;
            n+=start;
        }
    }
    return n;

   }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
      string p=normalize(pattern);
      vector<string> ans;
      for(auto a :words){
        if(normalize(a)==p){
            ans.push_back(a);

        }
      }
     return ans;
    }
};
