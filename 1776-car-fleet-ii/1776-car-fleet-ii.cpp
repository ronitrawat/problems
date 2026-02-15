class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        stack<int> st;
        int n=cars.size();
        
        vector<double> answer(n,-1);
        
        for(int i=n-1;i>=0;i--){
       
        while(!st.empty() && cars[st.top()][1]>=cars[i][1]){
              st.pop();
            }
           
        while(!st.empty()){
               double currTime=(double)(cars[st.top()][0]-cars[i][0])/(cars[i][1]-cars[st.top()][1]);

               if(answer[st.top()]==-1 || currTime<=answer[st.top()]){
                 answer[i]=currTime;
                 break;
               }
               st.pop();
        }
          
          st.push(i);


           

            
        }
           return answer;
    }
};