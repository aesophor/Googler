// Runtime: 24 ms, faster than 98.16% of C++ online submissions for Palindrome Linked List.
// Memory Usage: 13.1 MB, less than 32.98% of C++ online submissions for Palindrome Linked List.

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
    bool isPalindrome(ListNode* head) {
        int size = getSize(head);
        stack<int> st;
        
        if (size % 2 == 0) { // first type of palin
            for (int i = 0; i < size / 2; i++) {
                st.push(head->val);
                head = head->next;
            }
            for (int i = 0; i < size / 2; i++) {
                if (st.top() == head->val) {
                    st.pop();
                    head = head->next;
                } else {
                    return false;
                }
            }
        } else { // second type
            int mid = size / 2;
            for (int i = 0; i < mid; i++) {
                st.push(head->val);
                head = head->next;
            }
            head = head->next; // skip the mid node
            for (int i = mid + 1; i < size; i++) {
                if (st.top() == head->val) {
                    st.pop();
                    head = head->next;
                } else {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    inline int getSize(ListNode* head) {
        int size = 0;
        while (head) {
            head = head->next;
            size++;
        }
        return size;
    }
};

// Two kinds of palindrome
// 1. abba ab | ba
// 2. aba a | a
