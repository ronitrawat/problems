class Solution {
public:

    ListNode* head;

    int getSize(ListNode* head){

        int n = 0;

        while(head){

            n++;

            head = head->next;
        }

        return n;
    }

    TreeNode* build(int left,
                    int right){

        if(left > right){
            return NULL;
        }

        int mid =
            left + (right-left)/2;

        // build left subtree
        TreeNode* leftChild =
            build(left, mid-1);

        // current node becomes root
        TreeNode* root =
            new TreeNode(head->val);

        root->left = leftChild;

        // move list pointer
        head = head->next;

        // build right subtree
        root->right =
            build(mid+1, right);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {

        this->head = head;

        int n = getSize(head);

        return build(0, n-1);
    }
};