class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2!=0){
            return false;
        }
        stack<char> st;
        for(auto c: s){
            if(c=='(' || c=='{' || c=='['){
                st.push(c);
            }
            else if(c=='}'){
                if(!st.empty() && st.top()=='{'){
                    st.pop();
                }
                else{
                    return false;
                }
                
            }
             else if(c==')'){
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
                else{
                    return false;
                }
                
            }
             else if(c==']'){
                if(!st.empty() && st.top()=='['){
                    st.pop();
                }
                else{
                    return false;
                }
                
            }
        }
        return st.empty();
    }
};