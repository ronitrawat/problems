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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=NULL;
        ListNode* forward=head;
        while(forward){
            curr=forward;
            forward=forward->next;
            curr->next=prev;
            prev=curr;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int l=0;
        ListNode* temp=head;
        
        ListNode* rev =reverse(head);
        temp=rev;
        ListNode* prev=NULL;
        
        while(temp ){
            if(l==n-1){
                if(prev==NULL){
                    rev=temp->next;
                }
                else{
               prev->next=temp->next;}
               
               temp->next=NULL;
               
            }
            prev=temp;
            temp=temp->next;
            l++;
        }
        rev=reverse(rev);
        return rev;
    }
};