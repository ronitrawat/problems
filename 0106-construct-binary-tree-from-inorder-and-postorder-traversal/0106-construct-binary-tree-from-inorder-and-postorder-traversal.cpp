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

    
    TreeNode* solve(vector<int> inorder,vector<int> postorder,int& postorderIndex,int inorderStart,int inorderEnd ){
      
    if(postorderIndex<0){
        return NULL;
    }  
    if(inorderStart>inorderEnd){
        return NULL;
    }
    int ele=postorder[postorderIndex--];
    TreeNode* root=new TreeNode(ele);


    int inorderIndex=m[ele];

    root->right=solve(inorder,postorder,postorderIndex,inorderIndex+1,inorderEnd);
    root->left=solve(inorder,postorder,postorderIndex,inorderStart,inorderIndex-1);
    

    return root;
    }



    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       int n=postorder.size();
        int postorderIndex=n-1;
        int inorderStart=0;
        int inorderEnd=inorder.size()-1;
        mapping(inorder);

        TreeNode* root=solve(inorder,postorder,postorderIndex,inorderStart,inorderEnd);
        return root;
    }
};