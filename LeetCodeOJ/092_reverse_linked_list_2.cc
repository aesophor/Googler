// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Reverse Linked List II.
// Memory Usage: 8.7 MB, less than 91.76% of C++ online submissions for Reverse Linked List II.

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) {
            return head;
        }
        
        // Find the head node.
        ListNode* m_ptr = head;
        ListNode* m_ptr_prev = nullptr;
        int i = 1;
        while (m_ptr) {
            if (i == m) {
                break;
            }
            m_ptr_prev = m_ptr;
            m_ptr = m_ptr->next;
            i++;
        }
        
        // Find the tail node.
        ListNode* n_ptr = head;
        ListNode* n_ptr_next = nullptr;
        i = 1;
        while (n_ptr) {
            if (i == n) {
                break;
            }
            n_ptr = n_ptr->next;
            i++;
        }
        n_ptr_next = n_ptr->next;
        
        // If m == 1, the new head will be n.
        if (m == 1) {
            head = n_ptr;
        }
        
        // Reverse the bitch
        pair<ListNode*, ListNode*> head_tail = reverse(m_ptr, n - m + 1);
        
        // Relink it
        if (m_ptr_prev) {
            m_ptr_prev->next = head_tail.first;
        }
        head_tail.second->next = n_ptr_next;
        
        return head;
    }
    
    pair<ListNode*, ListNode*> reverse(ListNode* head, int count) {
        ListNode* new_tail = head;
        
        ListNode* prev = nullptr;
        for (int i = 0; i < count; i++) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return std::make_pair(prev, new_tail);
    }
};

//    1->2->3->4->5->NULL

// NULL<-2<-3<-4
