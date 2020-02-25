// Runtime: 8 ms, faster than 92.07% of C++ online submissions for Reverse Linked List.
// Memory Usage: 9.9 MB, less than 5.34% of C++ online submissions for Reverse Linked List.

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
  ListNode* reverseList(ListNode* head) {
    if (!head) {
      return nullptr;
    } 
    
    reverseHelper(head);
    head->next = nullptr;
    return new_head_;
  }
  
 private:
  ListNode* reverseHelper(ListNode* node) {
    if (!node->next) {
      new_head_ = node;
      return node;
    }
    
    reverseHelper(node->next)->next = node;
    return node;
  }
  
  ListNode* new_head_;
};
