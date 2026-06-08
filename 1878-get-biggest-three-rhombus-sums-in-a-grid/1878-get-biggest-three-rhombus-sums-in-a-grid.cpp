class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        unordered_set<int> seen;

        
        priority_queue<
            int,
            vector<int>,
            greater<int>
        > pq;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                
                int sum = grid[i][j];

                if(seen.insert(sum).second) {

                    pq.push(sum);

                    if(pq.size() > 3)
                        pq.pop();
                }

                
                for(int r = 1; ; r++) {

                    if(i-r < 0 || i+r >= n ||
                       j-r < 0 || j+r >= m)
                        break;

                    sum = 0;

                    int x = i-r;
                    int y = j;

                    
                    for(int k = 0; k < r; k++)
                        sum += grid[x++][y++];

                    
                    for(int k = 0; k < r; k++)
                        sum += grid[x++][y--];

                    
                    for(int k = 0; k < r; k++)
                        sum += grid[x--][y--];

                
                    for(int k = 0; k < r; k++)
                        sum += grid[x--][y++];

                    if(seen.insert(sum).second) {

                        pq.push(sum);

                        if(pq.size() > 3)
                            pq.pop();
                    }
                }
            }
        }

        vector<int> ans;

        while(!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};