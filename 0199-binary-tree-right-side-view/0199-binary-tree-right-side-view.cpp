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
    vector<int> rightSideView(TreeNode* root) {
     queue<TreeNode*> q;
     vector<int> ans;
     vector<int> temp;
     if(root==NULL){
      return ans;
     }  
     q.push(root);
     while(!q.empty()){
        int s =q.size();
        while(s--){
            TreeNode* it=q.front();
            q.pop();
            temp.push_back(it->val);
            if(it->right){
            q.push(it->right);}
            if(it->left){
            q.push(it->left);}
        }
        ans.push_back(temp[0]);
        temp.clear();
     }
     return ans;
    }
};