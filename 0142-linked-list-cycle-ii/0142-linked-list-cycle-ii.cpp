/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        int timer=0;
        map<ListNode*,int> mp;

        ListNode* temp=head;
        while(temp){
            
            if(mp.find(temp)!=mp.end()){
                return temp;
            }
            else{
                mp[temp]=timer;
                temp=temp->next;
                timer++;
            }


        }
        return NULL;




    }
};