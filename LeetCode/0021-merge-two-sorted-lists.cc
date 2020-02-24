// Runtime: 8 ms, faster than 89.75% of C++ online submissions for Merge Two Sorted Lists.
// Memory Usage: 9.7 MB, less than 5.74% of C++ online submissions for Merge Two Sorted Lists.

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
    ListNode* head = nullptr;
    ListNode* current = nullptr;
    
    while (l1 || l2) {
      int nextVal = 0;
      ListNode* newNode = nullptr;

      if (l1 && !l2) {
        nextVal = l1->val;
        l1 = l1->next;
        
      } else if (!l1 && l2) {
        nextVal = l2->val;
        l2 = l2->next;
        
      } else {  // l1 && l2
        if (l1->val <= l2->val) {
          nextVal = l1->val;
          l1 = l1->next;
        } else {
          nextVal = l2->val;
          l2 = l2->next;
        }
      }
      
      newNode = new ListNode(nextVal);
      
      if (!head) {
        head = newNode;
      } else {
        current->next = newNode;
      }
      current = newNode;
    }
    
    return head;
  }
};
