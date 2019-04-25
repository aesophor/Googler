// Runtime: 12 ms, faster than 99.58% of C++ online submissions for Linked List Cycle.
// Memory Usage: 9.8 MB, less than 47.36% of C++ online submissions for Linked List Cycle.

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
  bool hasCycle(ListNode* head) {
    // 爽指針大法！！嘿嘿
    ListNode* slow = head; // increment by 1 at once
    ListNode* fast = head; // increment by 2 at once
    
    while (fast) {
      slow = slow->next;
      fast = fast->next;
      if (fast) {
        fast = fast->next;
      }
      
      // Prevent comparing slow with fast pointer
      // when they are both nullptrs
      if (slow && fast && slow == fast) {
        return true;
      }
    }
    
    return false;
  }
};


// 騷年，太暴力了
/*
class Solution {
public:
  bool hasCycle(ListNode* head) {
    unordered_set<ListNode*> visited_nodes;
    
    while (head) {
      // If we can find this node, then
      // it means there's a cycle in the linked list.
      if (visited_nodes.find(head) != visited_nodes.end()) {
        return true;
      }
      visited_nodes.insert(head);
      head = head->next;
    }
    
    return false;
  }
};
*/
