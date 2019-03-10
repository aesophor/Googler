// Runtime: 8 ms, faster than 99.75% of C++ online submissions for Remove Nth Node From End of List.
// Memory Usage: 9.7 MB, less than 30.64% of C++ online submissions for Remove Nth Node From End of List.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes;
        ListNode* ptr = head;
        
        while (ptr) {
            nodes.push_back(ptr);
            ptr = ptr->next;
        }
        
        int pos = nodes.size() - n;
        
        if (pos == 0) {
            if (head) {
                return head->next;
            } else {
                return nullptr;
            }
        } else if (pos == nodes.size() - 1) {
            nodes.at(pos - 1)->next = nullptr;
            return head;
        } else {
            nodes.at(pos - 1)->next = nodes.at(pos + 1);
            return head;
        }
    }
};
