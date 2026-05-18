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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
     vector<vector<int>> ans;
     vector<int> a;
     if(root==NULL){
        return ans;
     }
     queue<TreeNode* > q;
     int count=1;
     q.push(root);

     while(!q.empty()){
        int s=q.size();
        while(s--){
            TreeNode* node=q.front();
            a.push_back(node->val);
            q.pop();
            if(node->left!=NULL){
            q.push(node->left);}
            if(node->right!=NULL){
            q.push(node->right);}

        }
        if(count%2==0){
            reverse(a.begin(),a.end());
        }
        count++;
        ans.push_back(a);
        a.clear();

     }
     return ans;      
    }
};