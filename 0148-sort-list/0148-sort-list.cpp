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
    ListNode* sortList(ListNode* head) {
       ListNode* temp=head;
       vector<int> a;
       while(temp){
        a.push_back(temp->val);
        temp=temp->next;
       } 
       sort(a.begin(),a.end());
       temp=head;
       int i=0;
       while(temp){
        temp->val=a[i];
        temp=temp->next;
        i++;
       }
       return head;
    }
};