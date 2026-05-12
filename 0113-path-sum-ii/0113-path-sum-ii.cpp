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
    void solve(TreeNode* root,int targetSum){
        if(root==NULL){
            return ;
        }
        a.push_back(root->val);

    if(root->left==NULL&& root->right==NULL){
        if(targetSum-root->val==0){
        
            ans.push_back(a);
            
        }
        
    }
    solve(root->left,targetSum-root->val);
    solve(root->right,targetSum-root->val);
    
    a.pop_back();
     
    }


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    solve(root,targetSum);  
       return ans;
        }
};