// Runtime: 12 ms, faster than 92.42% of C++ online submissions for Linked List Cycle II.
// Memory Usage: 9.9 MB, less than 20.40% of C++ online submissions for Linked List Cycle II.

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
  ListNode* detectCycle(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    
    while (fast && slow) {
      slow = slow->next;
      fast = fast->next;
      if (fast) {
        fast = fast->next;
      }
      
      if (fast && slow && fast == slow) {
        break;
      }
    }
    if (!fast || !slow) {
      return nullptr;
    }
    
    fast = head;
    while (fast != slow) {
      slow = slow->next;
      fast = fast->next;
      if (fast == slow) {
        break;
      }
    }
    return fast;
  }
};
