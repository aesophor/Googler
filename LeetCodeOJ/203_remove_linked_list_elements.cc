// Runtime: 28 ms, faster than 99.78% of C++ online submissions for Remove Linked List Elements.
// Memory Usage: 11.3 MB, less than 64.98% of C++ online submissions for Remove Linked List Elements.

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
        ListNode* ptr = head;
        
        while (ptr) {
            if (ptr->val == val) { // something like [1] 1
                head = head->next;
            } else if (ptr->next && ptr->next->val == val) {
                ListNode* tmp = ptr->next;
                while (tmp && tmp->val == val) {
                    tmp = tmp->next;
                }
                ptr->next = tmp;
            }
            ptr = ptr->next;
        }
        return head;
    }
};
