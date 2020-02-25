// Runtime: 4 ms, faster than 93.03% of C++ online submissions for Remove Nth Node From End of List.
// Memory Usage: 9 MB, less than 5.26% of C++ online submissions for Remove Nth Node From End of List.

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
    // Maintain two extra pointers with distance = n + 1
    ListNode* slow = head;
    ListNode* fast = head;
    
    // Setup fast pointer.
    for (int i = 0; i < n + 1; i++) {
      if (!fast) {
        return head->next;
      }
      fast = fast->next;
    }
    
    while (fast) {
      fast = fast->next;
      slow = slow->next;
    }
    
    slow->next = slow->next->next;
    return head;
  }
};
