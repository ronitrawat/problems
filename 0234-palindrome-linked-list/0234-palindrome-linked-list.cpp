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
   ListNode* middleFind(ListNode* head,ListNode* &midprev){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                midprev=slow;
                slow=slow->next;
            }
        }
        return slow;
    
   }
   int findLength(ListNode* head){
    ListNode* temp =head;
    
    int count =1;
    while(temp->next!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
   }
   ListNode* reverse(ListNode* head){
    ListNode* prev=NULL;
    ListNode* curr=NULL;
    ListNode* forward=head;
    while(forward!=NULL){
        curr=forward;
        forward=forward->next;
        curr->next=prev;
        prev=curr;
    }
    return curr;
   }
    bool isPalindrome(ListNode* head) {
        
        int length=findLength(head);
        if( length==1){
            return true;
        }


        ListNode* midprev=head;
        ListNode* middle=middleFind(head,midprev);
        midprev->next=NULL;
        ListNode* second=reverse(middle);
        ListNode* temp =head;
        while(temp!=NULL){
            if(temp->val!=second->val){
                return false;
            }
            else{
                temp=temp->next;
                second=second->next;
            }
            
        }
      return true;
    }
};