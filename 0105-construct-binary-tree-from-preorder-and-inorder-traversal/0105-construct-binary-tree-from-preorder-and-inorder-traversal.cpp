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
    unordered_map<int,int> m;
    void mapping(vector<int> inorder){
     for(int i=0;i<inorder.size();i++){
        m[inorder[i]]=i;
     }
     

    }
    TreeNode* construct(vector<int>  &inorder,vector<int> &preorder,int& preorderIndex,int inorderStart,int inorderEnd){
        if(preorderIndex>=preorder.size()){
            return NULL;
        }
        if(inorderStart>inorderEnd){
            return NULL;
        }
        int element=preorder[preorderIndex++];
        TreeNode* root=new TreeNode(element);

        int inorderIndex=m[element];

        root->left=construct(inorder,preorder,preorderIndex,inorderStart,inorderIndex-1);
        root->right=construct(inorder,preorder,preorderIndex,inorderIndex+1,inorderEnd);

        return root;

          


    }



    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
     mapping(inorder);
     int inorderStart=0;
     int inorderEnd=inorder.size();
     int preorderIndex=0;
     
     TreeNode* root=construct(inorder,preorder,preorderIndex,inorderStart,inorderEnd);

      return root;
    }
};