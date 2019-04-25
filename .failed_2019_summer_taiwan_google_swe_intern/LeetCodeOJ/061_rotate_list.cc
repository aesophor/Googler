// Runtime: 12 ms, faster than 99.52% of C++ online submissions for Rotate List.
// Memory Usage: 10.1 MB, less than 92.19% of C++ online submissions for Rotate List.

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
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head || k == 0) {
      return head;
    }
    
    int size = getListSize(head);
    k %= size;
    
    if (k == 0) {
      return head;
    }
    
    ListNode* ptr = head;
    ListNode* old_head = head;
    ListNode* new_tail = nullptr;
    int new_head_idx = size - k;
    for (int i = 0; i < new_head_idx; i++) {
      if (i == new_head_idx - 1) {
        new_tail = ptr;
      }
      ptr = ptr->next;
    }
    
    head = ptr;
    while (ptr->next) {
      ptr = ptr->next;
    }
    ptr->next = old_head;
    new_tail->next = nullptr;
    
    return head;
  }

private:
  int getListSize(ListNode* head) {
    int size = 0;
    while (head) {
      head = head->next;
      size++;
    }
    return size;
  }
};

// 0 1 2
//   ^ new head (step 3 - 2 = 1 from old head)
// 1 2 0 <- rotate by 2
