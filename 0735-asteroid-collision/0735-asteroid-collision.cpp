class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> st;
        for(auto a:asteroids){
            if(a>0){
                st.push(a);
            }
            else {
                while(!st.empty() && st.top()>0 && st.top()<-(a)){
                st.pop();
            }
            
            if(st.empty() || st.top()<0 ){
                st.push(a);
            }
            else if( st.top()==-a){
                st.pop();
            }

           
        }}
        vector<int> ans;
        while(!st.empty()){
            auto it=st.top();
            st.pop();
            ans.push_back(it);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};