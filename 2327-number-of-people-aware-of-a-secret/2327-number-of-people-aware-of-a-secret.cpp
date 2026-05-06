class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
       int mod =1e9+7;

       queue<pair<int,int>> spreadDay;
       queue<pair<int,int>> stopDay;
       
       spreadDay.push({1+delay,1});
       stopDay.push({1+forget,1});

       long long int ans=0;

       long long int spread=0;


       for(int i=2;i<=n;i++){
       while(!spreadDay.empty() &&  spreadDay.front().first==i){
        int newPeople=spreadDay.front().second;
        spread=(spread+newPeople)% mod;
        
        spreadDay.pop();
       }

       while(!stopDay.empty() && stopDay.front().first==i){
        int removePeople=stopDay.front().second;
        spread=(spread-removePeople+mod)%mod;
        stopDay.pop();
       }
       if(spread>0){
        spreadDay.push({i+delay,spread});
        stopDay.push({i+forget,spread});
       }


       }
       while(!stopDay.empty()){
        ans=(ans+stopDay.front().second)%mod;
        stopDay.pop();
       }

        return ans;
    }
};