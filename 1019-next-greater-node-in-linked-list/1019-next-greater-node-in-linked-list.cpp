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
    vector<int> nextLargerNodes(ListNode* head) {
     
        ListNode* temp=head;
        int n=0;
         vector<int> input;
        while(temp){
            input.push_back(temp->val);
            n++;
            temp=temp->next;
        }
          
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        for(int i=input.size()-1;i>=0;i--){
            int element=input[i];
            while(s.top()!=-1 && input[s.top()]<=element){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]==-1){
                ans[i]=0;
            }
            else{
                ans[i]=input[ans[i]];
            }
        }
        return ans;
    }
};