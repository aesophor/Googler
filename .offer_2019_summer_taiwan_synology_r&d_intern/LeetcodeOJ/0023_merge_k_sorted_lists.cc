// Runtime: 316 ms, faster than 13.65% of C++ online submissions for Merge k Sorted Lists.
// Memory Usage: 11.5 MB, less than 51.19% of C++ online submissions for Merge k Sorted Lists.

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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) {
      return nullptr;
    }
    
    ListNode* newHead = nullptr;
    ListNode* current = nullptr;
    
    while (!hasTraversedAllNodes(lists)) {
      int minVal = INT_MAX;
      ListNode** minNodePtr = nullptr;
      
      for (auto& listNode : lists) {
        if (listNode && listNode->val < minVal) {
          minNodePtr = &listNode;
          minVal = listNode->val;
        }
      }
      
      ListNode* newNode = new ListNode((*minNodePtr)->val);
      *minNodePtr = (*minNodePtr)->next;
      
      if (!newHead) {
        newHead = newNode;
      } else {
        current->next = newNode;
      }
      current = newNode;
    }
    
    return newHead;
  }
  
 private:
  bool hasTraversedAllNodes(const vector<ListNode*>& lists) {
    for (auto listNode : lists) {
      if (listNode) {
        return false;
      }
    }
    return true;
  }
};
