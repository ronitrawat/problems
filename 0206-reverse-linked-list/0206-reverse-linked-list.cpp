/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    void reverseLinkedList(ListNode* &prev,ListNode* &curr,ListNode* &forward){
        curr=forward;
        forward=forward->next;
        curr->next=prev;
        prev=curr;
    }


    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=prev;
        ListNode* forward=head;
        while(forward!=NULL){
            reverseLinkedList(prev,curr,forward);
        }
        return prev;
    }
};