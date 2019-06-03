// Runtime: 48 ms, faster than 93.97% of C++ online submissions for Intersection of Two Linked Lists.
// Memory Usage: 16.8 MB, less than 40.52% of C++ online submissions for Intersection of Two Linked Lists.

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
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* p1 = headA;
    ListNode* p2 = headB;
    
    bool isP1SecondRound = false;
    bool isP2SecondRound = false;
    
    while (p1 && p2 && p1 != p2) {
      p1 = p1->next;
      p2 = p2->next;
      
      if (!p1 && !isP1SecondRound) {
        p1 = headB;
        isP1SecondRound = true;
      }
      
      if (!p2 && !isP2SecondRound) {
        p2 = headA;
        isP2SecondRound = true;
      }
    }
    
    return (p1 == p2) ? p1 : nullptr;
  }
};
