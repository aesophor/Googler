// Runtime: 20 ms, faster than 87.87% of C++ online submissions for Add Two Numbers.
// Memory Usage: 10.2 MB, less than 91.43% of C++ online submissions for Add Two Numbers.

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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = nullptr;
    ListNode* current = nullptr;
    bool carry = false;

    while (l1 || l2 || carry) {
      int newVal = 0;
      if (l1) {
        newVal += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        newVal += l2->val;
        l2 = l2->next;
      }
      if (carry) {
        newVal++;
        carry = false;
      }
      if (newVal >= 10) {
        carry = true;
        newVal -= 10;
      }
      
      ListNode* newNode = new ListNode(newVal);
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
