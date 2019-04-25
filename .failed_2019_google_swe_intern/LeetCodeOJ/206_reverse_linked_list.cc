// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Reverse Linked List.
// Memory Usage: 9 MB, less than 92.33% of C++ online submissions for Reverse Linked List.

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
        ListNode* prev = nullptr;
        ListNode* ptr = head;

        while (ptr) {
            ListNode* next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next;
        }
        return prev;
    }
};

//       1->2->3->4->5->NULL

// NULL<-1<-2<-3<-4<-5


/* Using a stack
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
*/
