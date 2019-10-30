// Runtime: 28 ms, faster than 66.48% of C++ online submissions for Remove Linked List Elements.
// Memory Usage: 10.9 MB, less than 100.00% of C++ online submissions for Remove Linked List Elements.

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
    ListNode* current = head;
    
    while (current) {
      if (current->val == val) {
        if (!current->next) {
          prev->next = nullptr;
        }
        current = current->next;
      } else {
        if (prev) {
          prev->next = current;
        }
        prev = current;
        current = current->next;
      }
    }
    
    return head;
  }
};
