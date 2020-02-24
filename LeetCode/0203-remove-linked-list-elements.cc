// Runtime: 32 ms, faster than 69.88% of C++ online submissions for Remove Linked List Elements.
// Memory Usage: 12.9 MB, less than 5.66% of C++ online submissions for Remove Linked List Elements.

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
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* prev = nullptr;
    ListNode* ptr = head;
    
    while (ptr) {
      if (head->val == val) {
        head = head->next;
        ptr = head;
        continue;
      }
      
      if (ptr->val == val) {
        prev->next = ptr->next;
      } else {
        prev = ptr;  
      }

      ptr = ptr->next;
    }
    
    return head;
  }
};
