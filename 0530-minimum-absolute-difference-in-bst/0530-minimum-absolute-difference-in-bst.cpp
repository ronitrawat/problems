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
    int ans=INT_MAX;
    TreeNode* prev=NULL;
    void solve(TreeNode* root){
        if(root==NULL){
            return;
        }
        
        solve(root->left);
        if(prev==NULL){
            prev=root;
            
        }
        else{
        int diff=abs(root->val-prev->val);
        ans=min(ans,diff);
        prev=root;}
        solve(root->right);

    }
    int getMinimumDifference(TreeNode* root) {
        solve(root);
        return ans;
        
    }
};