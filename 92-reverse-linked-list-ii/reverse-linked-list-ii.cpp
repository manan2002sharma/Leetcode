class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (!head || m == n)
      return head;

    ListNode dummy(0, head);
    ListNode* prev = &dummy;

    for (int i = 0; i < m - 1; ++i)
      prev = prev->next;  

    ListNode* tail = prev->next;  

    for (int i = 0; i < n - m; ++i) {
      ListNode* temp = tail->next;
      tail->next = temp->next;
      temp->next = prev->next;
      prev->next = temp;
    }

    return dummy.next;
  }
};