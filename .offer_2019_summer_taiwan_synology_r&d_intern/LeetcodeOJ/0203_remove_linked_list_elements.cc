// Runtime: 28 ms, faster than 90.02% of C++ online submissions for Remove Linked List Elements.
// Memory Usage: 10.9 MB, less than 90.11% of C++ online submissions for Remove Linked List Elements.

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
  ListNode* removeElements(ListNode* head, int val) {
    while (head && head->val == val) {
      head = head->next;
    }
    
    ListNode* prev = nullptr;
    ListNode* ptr = head;
    while (ptr) {
      if (ptr->val == val) {
        prev->next = ptr->next;
      } else {
        prev = ptr;
      }
      ptr = ptr->next;
    }
    
    return head;
  }
};
