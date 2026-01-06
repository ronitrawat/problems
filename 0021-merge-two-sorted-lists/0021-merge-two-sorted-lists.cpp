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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> data;
        ListNode* a=list1;
        ListNode* b=list2;
        while(a){
            data.push_back(a->val);
            a=a->next;
        }
        while(b){
            data.push_back(b->val);
            b=b->next;
        }
        if(data.size()==0) return nullptr;
        sort(data.begin(),data.end());
        ListNode* head=new ListNode(data[0]);
         ListNode* temp =head;
        for(int i=1;i<data.size();i++){
           
                
                 
           
            
               
                temp->next=new ListNode(data[i]);
                temp=temp->next;
            
        }
        return head;
    }
};