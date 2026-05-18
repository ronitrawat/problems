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
    void level(TreeNode *root){
        queue<TreeNode *> q;
        if(root!=NULL){
          q.push(root);  
        }
        while(!q.empty()){
        
            int size=q.size();
            while(size--){
            TreeNode* n=q.front();
            a.push_back(n->val);
            q.pop();
            if(n->right!=NULL){
            q.push(n->right);
            }
            if(n->left!=NULL){
            q.push(n->left);}
            }
            ans.push_back(a);
            a.clear();
        }
    }


    vector<int> rightSideView(TreeNode* root) {
        level(root);
        vector<int> b;
        int n=ans.size();
        for(int i=0;i<n;i++){
            b.push_back(ans[i][0]);
        }
        return b;
    }
};