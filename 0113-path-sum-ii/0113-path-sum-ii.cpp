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
 vector<int> a;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
         
        
          if(root==NULL){
            return ans;
        }
        a.push_back(root->val);
        
        if(targetSum==root->val && root->right==NULL && root->left==NULL){
            ans.push_back(a);
        }
        pathSum(root->left,targetSum-root->val);
        pathSum(root->right,targetSum-root->val);

        a.pop_back();

    return ans;
    }
};