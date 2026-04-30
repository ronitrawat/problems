class Solution {
public:
    string predictPartyVictory(string senate) {
        
        queue<int> a;
        queue<int> b;

        int position=0;
        for(;position<senate.size();position++){

            char c=senate[position];
            if(c=='R'){
                a.push(position);
            }
            if(c=='D'){
                b.push(position);
            }
        }

        while(!a.empty() && !b.empty()){
            int z=a.front();
            a.pop();
            int x=b.front();
            b.pop();

            if(z<x){
                a.push(position++);
            }
            else{
                b.push(position++);
            }
        }
        if(a.empty()){
            return "Dire";
        }
        else{
            return "Radiant";
        }

    
    } 
};