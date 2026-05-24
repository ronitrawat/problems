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
    int path=0;
    void solve(TreeNode* root,int targetSum, long long int currSum,unordered_map<long long int,int>& m){
       
        if(root==NULL){
         return;
        }
        currSum+=root->val;
        if(currSum==targetSum){
            path++;
        }
        
        if(m.find(currSum-targetSum)!=m.end()){
            path+=m[currSum-targetSum];

        }
        m[currSum]++;

        
        solve(root->left,targetSum,currSum,m);
        solve(root->right,targetSum,currSum,m);
        m[currSum]--;

    }
    

    int pathSum(TreeNode* root, int targetSum) {
       int currSum=0;
       unordered_map<long long int,int> m;
       if(root){
       
        solve(root,targetSum,currSum,m);
        
        }
        return path;
    }
};