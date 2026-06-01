class BSTIterator {
public:

    stack<TreeNode*> s;

    void pushLeft(TreeNode* root){

        while(root){

            s.push(root);

            root = root->left;
        }
    }

    BSTIterator(TreeNode* root) {

        pushLeft(root);
    }

    int next() {

        TreeNode* temp = s.top();
        s.pop();

        // process right subtree
        if(temp->right){

            pushLeft(temp->right);
        }

        return temp->val;
    }

    bool hasNext() {

        return !s.empty();
    }
};