class Trie {
public:

    Trie* child[2];

    Trie() {
        child[0] = child[1] = nullptr;
    }

    void insert(int num) {

        Trie* node = this;

        for(int i=31;i>=0;i--) {

            int bit = (num>>i)&1;

            if(node->child[bit]==nullptr)
                node->child[bit]=new Trie();

            node=node->child[bit];
        }
    }

    int getMaxXor(int num) {

        Trie* node=this;

        int ans=0;

        for(int i=31;i>=0;i--) {

            int bit=(num>>i)&1;

            if(node->child[1-bit]) {

                ans |= (1<<i);

                node=node->child[1-bit];
            }
            else {

                node=node->child[bit];
            }
        }

        return ans;
    }
};

class Solution {
public:

    vector<int> maximizeXor(vector<int>& nums,
                            vector<vector<int>>& queries) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> q;

        for(int i=0;i<queries.size();i++) {

            int x = queries[i][0];
            int m = queries[i][1];

            q.push_back({m,x,i});
        }

        sort(q.begin(), q.end());

        Trie* root = new Trie();

        vector<int> ans(queries.size());

        int j = 0;

        for(auto &query : q) {

            int m   = query[0];
            int x   = query[1];
            int idx = query[2];

            while(j < nums.size() &&
                  nums[j] <= m) {

                root->insert(nums[j]);
                j++;
            }

            if(j == 0) {

                ans[idx] = -1;
            }
            else {

                ans[idx] = root->getMaxXor(x);
            }
        }

        return ans;
    }
};