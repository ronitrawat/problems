/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   vector<vector<int>> ans;

   void level(TreeNode* root){
      queue<TreeNode*> q;
     
      q.push(root);

      while(!q.empty()){
         vector<int> a;
        int s=q.size();
        while(s--){
        auto it=q.front();
        q.pop();
        a.push_back(it->val);
        if(it->left){
        q.push(it->left);
          }
          if(it->right){  q.push(it->right);
          }
        }
        ans.push_back(a);
      }
   }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            return ans;
        }
        level(root);
        return ans;
    }
};