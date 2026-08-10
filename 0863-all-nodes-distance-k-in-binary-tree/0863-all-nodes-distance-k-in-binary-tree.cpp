/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        map<TreeNode*,TreeNode*> m;
        queue<TreeNode*> q;
        q.push(root);
        m[root]=NULL;
        while(!q.empty()){
            int s =q.size();
            while(s--){
                TreeNode* node=q.front();
                q.pop();

                if(node->left){
                    q.push(node->left);
                    m[node->left]=node;
                }
                if(node->right){
                   q.push(node->right);
                   m[node->right]=node;
                }

            }
        }

        map<TreeNode*,int> visited;
        queue<TreeNode*> n;
        n.push(target);
        visited[target]=true;
        while(k){
            k--;
          
            int s =n.size();
            while(s--){
                  TreeNode* node=n.front();
            n.pop();
            if(node->left && !visited[node->left])
            n.push(node->left);
            visited[node->left]=true;
            
             if(node->right && !visited[node->right])
            n.push(node->right);
            visited[node->right]=true;

             if(m[node] && !visited[m[node]])
            n.push(m[node]);
            visited[m[node]]=true;

        }
        }

        while(!n.empty()){
            TreeNode* node=n.front();
            n.pop();
            ans.push_back(node->val);
        }
            return ans;
    }
};