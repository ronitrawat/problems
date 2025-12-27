class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char> a;
        char d='a';
        for(auto p: key){
            if(p==' '|| a.find(p)!=a.end()){
                continue;
            }
            else{
                a[p]=d;
                d++;
            }
        }
        string m="";
        for(auto p:message){
            if(p==' '){
                m.push_back(' ');
            }
            else{
            m.push_back(a[p]);
        }}
        return m;
    }
};