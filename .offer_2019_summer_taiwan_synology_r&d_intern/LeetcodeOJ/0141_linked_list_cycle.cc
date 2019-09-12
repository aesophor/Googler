// Runtime: 12 ms, faster than 92.15% of C++ online submissions for Linked List Cycle.
// Memory Usage: 9.7 MB, less than 68.59% of C++ online submissions for Linked List Cycle.

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
  bool hasCycle(ListNode* head) {
    if (head && !head->next) {
      return false;
    }
    
    ListNode* fast = head;
    ListNode* slow = head;
    
    while (fast && slow) {
      fast = fast->next;
      if (fast) {
        fast = fast->next;
      }
      slow = slow->next;
      
      if (fast && slow && fast == slow) {
        return true;
      }
    }
    return false;
  }
};

// [1]

// [1,2]
