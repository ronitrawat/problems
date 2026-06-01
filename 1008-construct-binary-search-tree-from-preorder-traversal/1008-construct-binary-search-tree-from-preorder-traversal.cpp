/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    int idx = 0;

    TreeNode* build(vector<int>& preorder, int upperBound) {

        // all elements used
        if(idx >= preorder.size()) {
            return NULL;
        }

        // current value cannot belong here
        if(preorder[idx] > upperBound) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;

        // left subtree -> values smaller than root
        root->left = build(preorder, root->val);

        // right subtree -> values smaller than ancestor bound
        root->right = build(preorder, upperBound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        return build(preorder, INT_MAX);
    }
};