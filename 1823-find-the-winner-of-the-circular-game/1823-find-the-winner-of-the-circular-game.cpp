class Solution {
public:
    int findTheWinner(int n, int k) {
        
        queue<int> players;
        for(int i=1;i<=n;i++){
        players.push(i);
        }
        while(players.size()>1){
            for(int i=1;i<k;i++){
                int j=players.front();
                players.pop();
                
                players.push(j);
            }
            players.pop();
        }
        return players.front();
    }
};