// Runtime: 8 ms, faster than 94.07% of C++ online submissions for Merge Two Sorted Lists.
// Memory Usage: 9.2 MB, less than 48.98% of C++ online submissions for Merge Two Sorted Lists.

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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* newHead = nullptr;
    ListNode* current = nullptr;
    
    while (l1 || l2) {
      ListNode* newNode = nullptr;
      if (l1 && !l2) {
        newNode = new ListNode(l1->val);
        l1 = l1->next;
      } else if (!l1 && l2) {
        newNode = new ListNode(l2->val);
        l2 = l2->next;
      } else {
        if (l1->val < l2->val) {
          newNode = new ListNode(l1->val);
          l1 = l1->next;
        } else {
          newNode = new ListNode(l2->val);
          l2 = l2->next;
        }
      }
      
      if (!newHead) {
        newHead = newNode;
        current = newNode;
      } else {
        current->next = newNode;
        current = newNode;
      }
    }
    return newHead;
  }
};
