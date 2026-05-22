class Solution {
public:

    TreeNode* getMin(TreeNode* root){

        while(root->left){
            root = root->left;
        }

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root == NULL){
            return NULL;
        }

     
        if(key < root->val){

            root->left =
                deleteNode(root->left,key);
        }

        else if(key > root->val){

            root->right =
                deleteNode(root->right,key);
        }

        else{

           
            if(!root->left && !root->right){

                delete root;

                return NULL;
            }

           
            else if(!root->left){

                TreeNode* temp = root->right;

                delete root;

                return temp;
            }

            
            else if(!root->right){

                TreeNode* temp = root->left;

                delete root;

                return temp;
            }

            
            else{

                TreeNode* mini =
                    getMin(root->right);

                root->val = mini->val;

                root->right =
                    deleteNode(root->right,
                               mini->val);
            }
        }

        return root;
    }
};