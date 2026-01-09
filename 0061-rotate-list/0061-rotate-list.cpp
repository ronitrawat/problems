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
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int> a;
        ListNode* temp=head;
        
        while(temp){
            a.push_back(temp->val);
            temp=temp->next;
            
        }
        int n=a.size();
        if(n==0){
            return head;
        }
        reverse(a.begin(),a.end());
        k=k%n;
        reverse(a.begin(),a.begin()+k);
        reverse(a.begin()+k,a.end());
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