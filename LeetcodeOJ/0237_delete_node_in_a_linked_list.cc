// Runtime: 8 ms, faster than 99.72% of C++ online submissions for Delete Node in a Linked List.
// Memory Usage: 9.3 MB, less than 17.35% of C++ online submissions for Delete Node in a Linked List.

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
    node->val = node->next->val;
    node->next = node->next->next;
  }
};
