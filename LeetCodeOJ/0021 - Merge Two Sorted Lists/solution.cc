// Runtime: 4 ms, faster than 98.95% of C++ online submissions for Merge Two Sorted Lists.
// Memory Usage: 8.9 MB, less than 72.13% of C++ online submissions for Merge Two Sorted Lists.

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
    if (!l1 && !l2) {
      return nullptr;
    }
    
    ListNode* head = nullptr;
    ListNode* current = nullptr;
    
    while (l1 || l2) {
      ListNode* newNode = nullptr;
      
      if (!l1) { // list1 search complete, search list2
        newNode = new ListNode(l2->val);
        l2 = l2->next;
      } else if (!l2) { // list2 search complete, search list1
        newNode = new ListNode(l1->val);
        l1 = l1->next;
      } else {
        if (l2->val >= l1->val) {
          newNode = new ListNode(l1->val);
          l1 = l1->next;
        } else { // l2->val < l1->val
          newNode = new ListNode(l2->val);
          l2 = l2->next;
        }
      }
      
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
