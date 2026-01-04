class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = dummy;

        while(curr->next){
            if(curr->next->val == val){
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;  
            }
            else{
                curr = curr->next;
            }
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};
