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
class Info{
    public: 
        int maxVal;
        int minVal;
        int sum;
        bool isBst;
        Info(int maxVal,int minVal,int sum,int isBst){
            this->maxVal=maxVal;
            this->minVal=minVal;
            this->sum=sum;
            this->isBst=isBst;
        }
};

class Solution {
public:
    int ans=0;
    Info solve(TreeNode* root){
    if(root==NULL){
        return Info(INT_MIN,INT_MAX,0,true);
    }
    Info leftAns=solve(root->left);

    Info rightAns=solve(root->right);

    
    if(leftAns.isBst && rightAns.isBst && root->val>leftAns.maxVal && root->val<rightAns.minVal){
        int currSum=root->val+leftAns.sum+rightAns.sum;
        ans=max(ans,currSum);
        return Info(max(root->val,rightAns.maxVal),min(root->val,leftAns.minVal),currSum,true);
    }

    return Info(INT_MIN,INT_MAX,0,false);

    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};