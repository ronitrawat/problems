class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        if(n==0){
            return true;
        }
        stack<int> a;
        for(int i=0;i<n;i++){
            if(a.empty()){
                a.push(s[i]);
            }
            else if(a.top()=='(' && s[i]==')'){
                a.pop();
            }
            else if(a.top()=='[' && s[i]==']'){
                a.pop();
            }
            else if(a.top()=='{' && s[i]=='}'){
                a.pop();
            }
            else{
                a.push(s[i]);
            }

        }
        if(a.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};