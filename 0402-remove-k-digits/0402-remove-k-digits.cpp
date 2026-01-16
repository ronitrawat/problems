class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> s;
        for(char c :num){
          if(k>0){
            while(!s.empty() && c-'0'<s.top()-'0' ){
                s.pop();
                k--;

                if(k==0){
                    break;
                }

            }
            }
            
                s.push(c);
            }

        
        while(k!=0 ){
          s.pop();
          k--;
        }
        string ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        while(ans.size()>0 && ans.back()=='0'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());

        return ans==""?"0":ans;
        }
    
};