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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr1=head;
        ListNode* ptr2=head;
        ListNode* prev=NULL;
        while(ptr1->next!=NULL){
            ptr1=ptr1->next;
            n--;
            if(n<=0){
                
                prev=ptr2;
                ptr2=ptr2->next;
            }
        }
        if(prev){
            prev->next=ptr2->next;
            return head;
        }
        
        head=head->next;
        return head;


    }
};