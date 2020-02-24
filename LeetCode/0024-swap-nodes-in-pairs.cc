// Runtime: 4 ms, faster than 73.19% of C++ online submissions for Swap Nodes in Pairs.
// Memory Usage: 8.9 MB, less than 5.36% of C++ online submissions for Swap Nodes in Pairs.

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
    if (!head) {
      return nullptr;
    }
    
    return helper(head, head->next);
  }
  
 private:
  ListNode* helper(ListNode* n1, ListNode* n2) {
    if (n1 && !n2) {
      return n1;
    }

    n1->next = (n2->next) ? helper(n2->next, n2->next->next) : nullptr;
    n2->next = n1;
    return n2;
  }
};
