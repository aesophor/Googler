// Runtime: 4 ms, faster than 96.47% of C++ online submissions for Remove Nth Node From End of List.
// Memory Usage: 8.6 MB, less than 63.65% of C++ online submissions for Remove Nth Node From End of List.

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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Maintain an extra pointer and update it with delay of n steps.
    ListNode* delayedPtr = head;
    ListNode* ptr = head;
    
    while (ptr->next) {
      if (--n < 0) {
        delayedPtr = delayedPtr->next;
      }
      ptr = ptr->next;
    }
    
    if (n == 1) { // remove head
      head = head->next;
    } else if (!delayedPtr->next->next) { // remove tail
      delayedPtr->next = nullptr;
    } else { // remove middle
      delayedPtr->next = delayedPtr->next->next;
    }
    
    return head;
  }
};

// [1], n=1
// [1,2] n=1
