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
        if(head==NULL) return NULL;
        
        ListNode* fast= head;
        ListNode* slow= head;
        while(fast->next!=NULL&&fast->next->next!=NULL&& fast!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                ListNode* entry=head;
                while(slow!=entry){
                    slow=slow->next;
                    entry=entry->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};