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
    

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> a;
        vector<int> b;
        
        ListNode* temp1=l1;
        ListNode* temp2=l2;

        while(temp1){
            a.push_back(temp1->val);
            temp1=temp1->next;
        }
        reverse(a.begin(),a.end());
        while(temp2){
            b.push_back(temp2->val);
            temp2=temp2->next;
        }
        reverse(b.begin(),b.end());

    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    vector<int> ans;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0) sum += a[i--];
        if (j >= 0) sum += b[j--];

        ans.push_back(sum % 10);
        carry = sum / 10;

    }
    
    ListNode* head = new ListNode(ans[0]);
    ListNode* temp = head;

    for(int i = 1; i < ans.size(); i++) {
        temp->next = new ListNode(ans[i]);
        temp = temp->next;
    }
    return head;
    }
};