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
        if(head==NULL||head->next==NULL) return head;
        ListNode* last= head;
        ListNode* shouldbelast=head;
        int size=1;
        int count=0;
        while(last->next!=NULL){
            last=last->next;
            size++;   
        }
        last= head;
        while(last->next!=NULL){
            last=last->next;
            count++;
            if(count>k%size) shouldbelast=shouldbelast->next;   
        }
        last->next=head;
        ListNode* newhead=shouldbelast->next;
        shouldbelast->next=NULL;
        return newhead;
    }
};