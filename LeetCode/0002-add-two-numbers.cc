// Runtime: 32 ms, faster than 36.04% of C++ online submissions for Add Two Numbers.
// Memory Usage: 11.8 MB, less than 5.14% of C++ online submissions for Add Two Numbers.

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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    bool carry = false;
    ListNode* result_head = nullptr;
    ListNode* result_current = nullptr;
    
    while (l1 || l2 || carry) {
      int new_digit = 0;
      
      if (carry) {
        new_digit += 1;
        carry = false;
      }
      
      if (l1) {
        new_digit += l1->val;
        l1 = l1->next;
      }
      
      if (l2) {
        new_digit += l2->val;
        l2 = l2->next;
      }
      
      if (new_digit >= 10) {
        carry = true;
        new_digit -= 10;
      }
      
      ListNode* new_node = new ListNode(new_digit);
      if (!result_head) {
        result_head = new_node;
      } else {
        result_current->next = new_node;
      }
      result_current = new_node;
    }
    
    return result_head;
  }
};
