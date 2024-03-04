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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head){
        if(head==NULL) return NULL;
        ListNode* ptr=head;
        while(ptr->next){
            ptr=ptr->next;
        }
        return createbbt(head,ptr);
    }
    TreeNode* createbbt(ListNode *ptr1,ListNode *ptr2){
        if(ptr1==NULL||ptr2==NULL) return NULL;
        if(ptr1==ptr2){
            TreeNode* temp=new TreeNode(ptr1->val);
            return temp;
        }
        ListNode* doublemove=ptr1;
        ListNode* mid=ptr1;
        ListNode* prev=NULL;
        while(doublemove!=ptr2&&doublemove->next!=ptr2){
            doublemove=doublemove->next->next;
            prev=mid;
            mid=mid->next;            
        }
        if(doublemove->next==ptr2){
            doublemove=doublemove->next;
        }
        TreeNode* node=new TreeNode(mid->val);
        node->left=createbbt(ptr1,prev);
        node->right=createbbt(mid->next,ptr2);
        return node; 
    }
        
};