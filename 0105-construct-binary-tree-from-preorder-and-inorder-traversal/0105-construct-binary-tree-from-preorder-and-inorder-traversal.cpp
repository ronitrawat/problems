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
    map<int,int> m;

    TreeNode* build(vector<int> &preorder,int &pStart,int iStart,int iEnd){
        if(pStart>=preorder.size()){
            return NULL;
        }
        if(iStart>iEnd){
            return NULL;
        }
        int element =preorder[pStart++];
        TreeNode* root=new TreeNode(element);

        int idx=m[element];

        root->left=build(preorder,pStart,iStart,idx-1);
        root->right=build(preorder,pStart,idx+1,iEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        int pStart=0;
        TreeNode* root=build(preorder,pStart,0,inorder.size()-1);
        return root;
    }
};