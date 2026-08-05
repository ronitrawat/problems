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

    vector<int> ans;
    

    vector<int> postorderTraversal(TreeNode* root) {
        if(!root){
            return ans;
        }
        stack<TreeNode*> st1,st2;
        st1.push(root);
        while(!st1.empty()){
            auto it=st1.top();
            st1.pop();
            st2.push(it);
            if(it->left){
                st1.push(it->left);
            }
            if(it->right){
                st1.push(it->right);
            }
        }
        while(!st2.empty()){
            auto it=st2.top();
            st2.pop();
            ans.push_back(it->val);
        }
        return ans;
    }
};