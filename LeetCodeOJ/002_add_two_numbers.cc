// Runtime: 40 ms, faster than 96.84% of C++ online submissions for Add Two Numbers.
// Memory Usage: 19.2 MB, less than 24.01% of C++ online submissions for Add Two Numbers.

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
        ListNode* result_first_digit = nullptr;
        ListNode* result_ptr = nullptr;
        bool carry = false;
        
        while (l1 || l2) {
            int digit1 = (l1) ? l1->val : 0;
            int digit2 = (l2) ? l2->val : 0;
            int new_digit = (carry) ? digit1 + digit2 + 1 : digit1 + digit2;
            carry = false;
            
            // If first digit isn't calculated
            ListNode* new_node = new ListNode(new_digit % 10);
            if (!result_first_digit) {
                result_first_digit = new_node;
            } else {
                result_ptr->next = new_node;
            }
            result_ptr = new_node;
            
            // 15 -> 5 , carry
            if (new_digit > 9) {
                carry = true;
            }
            
            l1 = (l1) ? l1->next : l1;
            l2 = (l2) ? l2->next : l2;
        }
        
        if (carry) {
            result_ptr->next = new ListNode(1);
        }
        
        return result_first_digit;
    }
};
