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
        if(!l1) return l2;//if l1 is empty return l2 same for l1
        if(!l2) return l1;
        ListNode* l= new ListNode();
        ListNode* ans=l;//created new list pointer to return as answer
        int carry=0;//on the basis of carry we will add value to current node
        while(l1||l2){//if any of l1 or l2 is not null
            int currentval;
            ListNode* newNode= new ListNode();//temporary node 
            if(l1&&l2){//if both l1 and l2 have a value than first we calculate currentval by adding l1 l2 and carry
                currentval=l1->val+l2->val+carry;
                if(currentval>9){//if currentval is more than 9 that means we have take care of carry
                    newNode->val=currentval%10;
                    carry=currentval/10;
                }else{//else we can directly add value
                    carry=0;
                    newNode->val=currentval;
                }
                l1=l1->next;
                l2=l2->next;
            }
            else if(l1){ //same thing what we did above just that now currentval will not have l2 as it is null
                currentval=l1->val+carry;
                if(currentval>9){
                    newNode->val=currentval%10;
                    carry=currentval/10;
                }else{
                    carry=0;
                    newNode->val=currentval;
                }
                l1=l1->next;
            }else{//same but this time l1 is null
                currentval=l2->val+carry;
                if(currentval>9){
                    newNode->val=currentval%10;
                    carry=currentval/10;
                }else{
                    carry=0;
                    newNode->val=currentval;
                }
                l2=l2->next;
            }
            
            l->next=newNode;
            l=l->next;
        }
        if(carry!=0){ //checking we there is carry at last if yes than add new node
            l->next=new ListNode(carry);
        }
        return ans->next; //return the ans from where we started storing answer
    }
};