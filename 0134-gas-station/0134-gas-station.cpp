class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int deposit=0;
      int balance=0;
      int start=0;

      for(int i=0;i<gas.size();i++){
        if(balance+gas[i]<cost[i]){
            deposit+=balance+gas[i]-cost[i];
            start=i+1;
            balance=0;
        }
        else{
            balance+=gas[i]-cost[i];
        }
        
        }
        if(balance+deposit>=0){
            return start;
        }
        else{
            return -1;
        }
      
      return -1;
    }
};