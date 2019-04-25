// Time limit exceeded Q_Q

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
    ListNode* sortList(ListNode* head) {
        int size = getSize(head);
        mergeSort(head, 0, size - 1);
        return head;
    }
    
private:
    inline int getSize(ListNode* head) const {
        int size = 0;
        while (head) {
            head = head->next;
            size++;
        }
        return size;
    }
    
    inline ListNode* getNode(ListNode* head, int index) const {
        for (int i = 0; i < index; i++) {
            head = head->next;
        }
        return head;
    }
    
    // Merge sort the linked list and returns the new head.
    void mergeSort(ListNode* head, int left, int right) const {
        if (left >= right) {
            return;
        }
        
        int mid = (left + right) / 2;
        mergeSort(head, left, mid);
        mergeSort(head, mid + 1, right);
        merge(head, left, mid, right);
    }
    
    // Merge two sublist and returns the new head.
    void merge(ListNode* head, int left, int mid, int right) const {
        // Get the pointer to left.
        ListNode* ptr = getNode(head, left);
        ListNode* left_ptr = ptr;
        ListNode* right_ptr = getNode(head, mid + 1);
        
        // 4->2  1->3
        // [4,2] [1,3]
        const int kLeftSize = mid - left + 1;
        const int kRightSize = right - mid;
        int left_current = 0;
        int right_current = 0;
        int left_vec[kLeftSize];
        int right_vec[kRightSize];
        for (int i = 0; i < kLeftSize; i++) {
            left_vec[i] = left_ptr->val;
            left_ptr = left_ptr->next;
        }
        for (int i = 0; i < kRightSize; i++) {
            right_vec[i] = right_ptr->val;
            right_ptr = right_ptr->next;
        }
        
        
        while (left_current < kLeftSize || right_current < kRightSize) {
            if (left_current == kLeftSize && right_current < kRightSize) {
                ptr->val = right_vec[right_current];
                right_current++;
            } else if (left_current < kLeftSize && right_current == kRightSize) {
                ptr->val = left_vec[left_current];
                left_current++;
            } else { // left_current < kLeftSize && right_current < kRightSize
                if (left_vec[left_current] <= right_vec[right_current]) {
                    ptr->val = left_vec[left_current];
                    left_current++;
                } else { // >
                    ptr->val = right_vec[right_current];
                    right_current++;
                }
            }
            ptr = ptr->next;
        }
    }
};
