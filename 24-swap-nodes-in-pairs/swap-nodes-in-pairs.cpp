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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* prev=new ListNode(0);
        ListNode* curr=head;
        head=curr->next;
        ListNode* nextt;
        while(curr!=NULL && curr->next!=NULL){
            nextt=curr->next;
            curr->next=nextt->next;
            nextt->next=curr;
            prev->next=nextt;
            curr=curr->next;
            prev=prev->next->next;

        }
        return head;
    }
};