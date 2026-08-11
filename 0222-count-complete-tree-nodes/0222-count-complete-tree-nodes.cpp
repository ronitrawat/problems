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
   int leftHeight(TreeNode* root){
    int h = 0;

    while(root){
        h++;
        root = root->left;
    }

    return h;
}

int rightHeight(TreeNode* root){
    int h = 0;

    while(root){
        h++;
        root = root->right;
    }

    return h;
}

    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(leftHeight(root)==rightHeight(root)){
           return  (1 << (leftHeight(root))) - 1;

        }
        else{
            int l=countNodes(root->left);
            int r=countNodes(root->right);
            return 1+l+r;
        }
    }
};