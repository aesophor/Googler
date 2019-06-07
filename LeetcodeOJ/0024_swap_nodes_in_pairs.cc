// Runtime: 4 ms, faster than 91.47% of C++ online submissions for Swap Nodes in Pairs.
// Memory Usage: 8.7 MB, less than 58.79% of C++ online submissions for Swap Nodes in Pairs.

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
  ListNode* swapPairs(ListNode* head) {
    return (head) ? helper(head, head->next) : nullptr;
  }
  
 private:
  ListNode* helper(ListNode* node1, ListNode* node2) {
    if (!node2) {
      return node1;
    }
    
    if (node2->next) {
      node1->next = helper(node2->next, node2->next->next);
    } else {
      node1->next = nullptr;
    }
    node2->next = node1;
    return node2;
  }
};
