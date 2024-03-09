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
private:
    void reverse(ListNode* &st,ListNode* end){
        
        ListNode* first=st->next;
        ListNode* newst=first;
        ListNode* second=first->next;
        first->next=end;
        while(second!=end){
            cout<<first->val<<"  "<<second->val<<endl;
            ListNode* temp=second->next;
            second->next=first;
            first=second;
            second=temp;
        }
        st->next=first;
        st=newst;
    }
public: 
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* st=dummy;
        ListNode* en=head;
        int c=1;
        while(c!=k){
            head=head->next;
            c++;
        }
        int count=0;
        bool chk = true;
        while(en!=NULL || chk ){ 
            if(en==NULL){
                chk=false;
                if(count==k)reverse(st,en);
            }
            else if(count!=k){
                count++;
                en = en->next;
            }
            else{
                count=0;
                reverse(st,en);
            }
        }
        return head;
    }
    
};