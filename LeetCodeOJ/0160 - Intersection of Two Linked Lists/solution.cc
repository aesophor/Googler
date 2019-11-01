// Runtime: 72 ms, faster than 10.91% of C++ online submissions for Intersection of Two Linked Lists.
// Memory Usage: 22.3 MB, less than 5.55% of C++ online submissions for Intersection of Two Linked Lists.

class Solution {
 public:
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    std::unordered_set<ListNode*> appeared;

    while (headA || headB) {
      if (appeared.find(headA) != appeared.end()) {
	return headA;
      }
      if (headA) {
	appeared.insert(headA);
	headA = headA->next;
      }

      if (appeared.find(headB) != appeared.end()) {
	return headB;
      }
      if (headB) {
	appeared.insert(headB);
	headB = headB->next;
      }
    }

    return nullptr;
  }
};

