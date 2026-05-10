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
        if(root==NULL)
        {
            return ;
        }
        q.push(root);
        
        vector<int> a;
        while(!q.empty()){
            int k=q.size();
            for(int i=1;i<=k;i++){
            TreeNode* ele=q.front();
            q.pop();
            a.push_back(ele->val);
                if(ele->left!=NULL){
                q.push(ele->left);}
                if(ele->right!=NULL){
                q.push(ele->right);}

            }
            ans.push_back(a);
            a.clear();
            
           
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