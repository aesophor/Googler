// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Reverse Linked List.
// Memory Usage: 9.1 MB, less than 78.69% of C++ online submissions for Reverse Linked List.

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
        stack<int> st;
        ListNode* ptr = head;
        while (ptr) {
            st.push(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        while (ptr) {
            ptr->val = st.top();
            st.pop();
            ptr = ptr->next;
        }
        
        return head;
    }
};
