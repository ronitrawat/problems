class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {

        int n = board.size();

        // Step 1: Convert board into connection array
        int node = 1;
        bool flag = true;

        vector<int> connection(n * n + 1, -1);

        for (int i = n - 1; i >= 0; i--) {

            if (flag) {

                for (int j = 0; j < n; j++) {

                    if (board[i][j] != -1) {
                        connection[node] = board[i][j];
                    }

                    node++;
                }

            } else {

                for (int j = n - 1; j >= 0; j--) {

                    if (board[i][j] != -1) {
                        connection[node] = board[i][j];
                    }

                    node++;
                }
            }

            flag = !flag;
        }

        // Step 2: Build Graph
        vector<vector<int>> graph(n * n + 1);

        for (int i = 1; i < n * n; i++) {

            for (int dice = 1; dice <= 6; dice++) {

                int nbr = i + dice;

                if (nbr <= n * n) {

                    if (connection[nbr] != -1) {
                        graph[i].push_back(connection[nbr]);
                    } else {
                        graph[i].push_back(nbr);
                    }
                }
            }
        }

        // Step 3: BFS (Shortest Path)
        queue<int> q;
        vector<int> visited(n * n + 1, 0);

        q.push(1);
        visited[1] = 1;

        int level = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                int pos = q.front();
                q.pop();

                if (pos == n * n) {
                    return level;
                }

                for (int nbr : graph[pos]) {

                    if (!visited[nbr]) {

                        visited[nbr] = 1;
                        q.push(nbr);
                    }
                }
            }

            level++;
        }

        return -1;
    }
};