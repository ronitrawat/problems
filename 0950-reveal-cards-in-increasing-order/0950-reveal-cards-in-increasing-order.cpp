class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> ans(deck.size());
        queue<int> d;
        sort(deck.begin(),deck.end());
        for(int i=0;i<deck.size();i++){
        d.push(i);
        } 
        for(int i=0;i<deck.size();i++){
           ans[d.front()]=deck[i];
            d.pop();

            if(!d.empty()){
                int j=d.front();
                d.pop();
                d.push(j);
                
            }
        }
        return ans;
    }
};