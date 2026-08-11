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

    TreeNode* build(vector<int> &postorder,int &pStart,int iStart,int iEnd){
        if(pStart<0){
            return NULL;
        }
        if(iStart>iEnd){
            return NULL;
        }
        int element =postorder[pStart--];
        TreeNode* root=new TreeNode(element);

        int idx=m[element];
        root->right=build(postorder,pStart,idx+1,iEnd);
        root->left=build(postorder,pStart,iStart,idx-1);
        

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        int pStart=postorder.size()-1;
        TreeNode* root=build(postorder,pStart,0,inorder.size()-1);
        return root;
    }
};