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
    ListNode* oddEvenList(ListNode* head) {
        vector<int> odd;
        vector<int> even;
        ListNode* temp=head;
        int l=1;
        while(temp){
            if(l&1){
                odd.push_back(temp->val);

            }
            else{
                even.push_back(temp->val);

            }
            l++;
            temp=temp->next;
        }
        temp=head;
      
        for(int x:odd){
            temp->val=x;
            
            temp=temp->next;
        }
        
        for(int y:even){
            temp->val=y;
            
            temp=temp->next;
        }
        return head;
    }
};