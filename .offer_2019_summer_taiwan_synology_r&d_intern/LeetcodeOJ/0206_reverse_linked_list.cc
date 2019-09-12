// Runtime: 4 ms, faster than 99.73% of C++ online submissions for Reverse Linked List.
// Memory Usage: 9.2 MB, less than 39.16% of C++ online submissions for Reverse Linked List.

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

// 1->2->3->4->5->NULL
// NULL<-1<-2<-3

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
    return reverse(nullptr, head);
  }
 private:
  ListNode* reverse(ListNode* node1, ListNode* node2) {
    if (!node2) {
      return node1;
    }
    
    ListNode* newHead = reverse(node2, node2->next);
    node2->next = node1;
    return newHead;
  }
};

// 1->2->3->4->5->NULL
// NULL<-1<-2<-3
