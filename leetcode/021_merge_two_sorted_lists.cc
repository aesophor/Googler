// Runtime: 12 ms, faster than 99.65% of C++ online submissions for Merge Two Sorted Lists.
// Memory Usage: 10.2 MB, less than 18.33% of C++ online submissions for Merge Two Sorted Lists.

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
        ListNode* ret_head = nullptr;
        ListNode* ret_ptr = nullptr;
        
        while (l1 || l2) {
            ListNode* new_node = nullptr;
            
            if (l1 && l2) {
                if (l1->val < l2->val) {
                    new_node = new ListNode(l1->val);
                    l1 = l1->next;
                } else {
                    new_node = new ListNode(l2->val);
                    l2 = l2->next;
                }
            } else if (l1 && !l2) {
                new_node = new ListNode(l1->val);
                l1 = l1->next;
            } else if (!l1 && l2) {
                new_node = new ListNode(l2->val);
                l2 = l2->next;
            }
            
            if (!ret_head) {
                ret_head = new_node;
            } else {
                ret_ptr->next = new_node;
            }
            ret_ptr = new_node;
        }
        
        return ret_head;
    }
};
