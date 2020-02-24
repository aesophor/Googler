// Runtime: 12 ms, faster than 92.34% of C++ online submissions for Delete Node in a Linked List.
// Memory Usage: 10.2 MB, less than 11.54% of C++ online submissions for Delete Node in a Linked List.

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
  void deleteNode(ListNode* node) {
    while (node->next) {
      node->val = node->next->val;
      
      if (!node->next->next) {
        node->next = nullptr;
      } else {
        node = node->next;    
      }
    }
  }
};
