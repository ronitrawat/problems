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
    void pred(TreeNode* current){
        while(current){
            if(!current->left){
                ans.push_back(current->val);
                current=current->right;
            }
            else{
                 TreeNode* pred = current->left;
                while(pred->right && pred->right!=current){
                    pred=pred->right;
                }
                if(pred->right==current){
                    pred->right=NULL;
                    ans.push_back(current->val);
                    current = current->right;

                }
                else{
                    pred->right=current;
                    current=current->left;
                }
            }
        }
        }
    
    vector<int> inorderTraversal(TreeNode* root) {
    
        if(!root){
            return ans;
        }
        TreeNode* current =root;
        pred(current);

        return ans;
        
    }
};