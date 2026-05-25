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
vector<TreeNode*> a;
    void preorder(TreeNode* root){
        if(root==NULL){
            return;

        }
        a.push_back(root);
       
        preorder(root->left);
        preorder(root->right);

        
    }
    void flatten(TreeNode* root) {
      if(!root){
        return; }
      preorder(root);

      for(int i = 0; i < a.size()-1; i++){

            a[i]->left = NULL;

            a[i]->right = a[i+1];
        }

        a[a.size()-1]->left = NULL;

        a[a.size()-1]->right = NULL;
    
      
    }
};