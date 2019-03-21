// Runtime: 12 ms, faster than 99.53% of C++ online submissions for Linked List Cycle II.
// Memory Usage: 9.8 MB, less than 45.37% of C++ online submissions for Linked List Cycle II.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Floyd's cycle detection
// https://www.youtube.com/watch?v=LUm2ABqAs1w&t=263s
class Solution {
public:
  ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    bool searching_loop_start_point = false;
    
    // Stage 1
    while (fast) {
      slow = slow->next;
      fast = fast->next;
      
      if (fast && !searching_loop_start_point) {
        fast = fast->next;
      }
      
      if (slow && fast && slow == fast) {
        if (!searching_loop_start_point) {
          slow = head;
          searching_loop_start_point = true;
          
          // [1,2] stage2 的時候 slow == fast == head
          // 所以這邊要進行比較
          if (slow == fast) { 
            return slow;
          }
        } else {
          return slow;
        }
      }
    }
    
    return nullptr;
  }
};

// 很暴力啊，小哥。。。
/*
class Solution {
public:
  ListNode* detectCycle(ListNode* head) {
    unordered_set<ListNode*> visited_nodes;
    
    while (head) {
      if (visited_nodes.find(head) != visited_nodes.end()) {
        return head;
      }
      
      visited_nodes.insert(head);
      head = head->next;
    }
    
    return nullptr;
  }
};
*/
