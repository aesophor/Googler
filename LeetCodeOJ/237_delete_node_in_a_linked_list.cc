// Runtime: 12 ms, faster than 100.00% of C++ online submissions for Delete Node in a Linked List.
// Memory Usage: 9.1 MB, less than 84.44% of C++ online submissions for Delete Node in a Linked List.

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
    void deleteNode(ListNode* node) {
        ListNode* prev = nullptr;
        while (node->next) {
            node->val = node->next->val;
            prev = node;
            node = node->next;
        }
        prev->next = nullptr;
    }
};
