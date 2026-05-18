class Solution {
public:

    int widthOfBinaryTree(TreeNode* root) {

        if(root == NULL) {
            return 0;
        }

        long long ans = 0;

        queue<pair<TreeNode*, long long>> q;

        q.push({root,0});

        while(!q.empty()) {

            int s = q.size();

            long long mini = q.front().second;

            long long first, last;

            for(int i = 0; i < s; i++) {

                auto temp = q.front();
                q.pop();

                TreeNode* node = temp.first;

                
                long long hd = temp.second - mini;

                if(i == 0) {
                    first = hd;
                }

                if(i == s-1) {
                    last = hd;
                }

                if(node->left) {
                    q.push({node->left, 2*hd + 1});
                }

                if(node->right) {
                    q.push({node->right, 2*hd + 2});
                }
            }

            ans = max(ans, last - first + 1);
        }

        return (int)ans;
    }
};