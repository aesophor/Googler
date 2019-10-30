// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Swap Nodes in Pairs.
// Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Swap Nodes in Pairs.

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
  ListNode* helper(ListNode* n1, ListNode* n2) {
    if (n1 && !n2) {
      return n1;
    } else if (!n2->next) {
      n1->next = nullptr;
      n2->next = n1;
      return n2;
    }
    
    n1->next = helper(n2->next, n2->next->next);
    n2->next = n1; 
    return n2;
  }
};
