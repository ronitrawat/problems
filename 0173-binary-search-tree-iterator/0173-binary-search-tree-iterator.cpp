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
class BSTIterator {
public:
    stack<TreeNode* > s;
    void reverseInorder(TreeNode* root){
        if(root==NULL){
            return ;
        }
        reverseInorder(root->right);
        s.push(root);
        reverseInorder(root->left);
    }
    BSTIterator(TreeNode* root) {
        reverseInorder(root);
        
    }
    
    int next() {
        int ans;
        if(s.size()>0){
            TreeNode* temp=s.top();
            s.pop();
            ans=temp->val;
        }
        return ans;
    }
    
    bool hasNext() {
        return (s.size()>0)?true:false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */