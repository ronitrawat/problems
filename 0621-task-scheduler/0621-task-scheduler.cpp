class cmp{
public:
    bool operator()(pair<char,int> a,
                    pair<char,int> b)
    {
        return a.second < b.second;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char,int> m;

        for(char ch : tasks){
            m[ch]++;
        }

        priority_queue<
            pair<char,int>,
            vector<pair<char,int>>,
            cmp
        > q;

        for(auto it : m){
            q.push(it);
        }

        int time = 0;

        while(!q.empty()){

            int cycle = n + 1;

            vector<pair<char,int>> temp;

            while(cycle > 0 && !q.empty()){

                auto curr = q.top();
                q.pop();

                curr.second--;

                if(curr.second > 0){
                    temp.push_back(curr);
                }

                time++;
                cycle--;
            }

            for(auto &x : temp){
                q.push(x);
            }

            if(q.empty()){
                break;
            }

            time += cycle;
        }

        return time;
    }
};