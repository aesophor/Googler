// Runtime: 396 ms, faster than 9.88% of C++ online submissions for Merge k Sorted Lists.
// Memory Usage: 12.9 MB, less than 5.95% of C++ online submissions for Merge k Sorted Lists.

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
    ListNode* head = nullptr;
    ListNode* current = nullptr;
    
    while (!allListTraversed(lists)) {
      ListNode* newNode = new ListNode(incMinList(lists));
      
      if (!head) {
        head = newNode;
      } else {
        current->next = newNode;
      }
      current = newNode;
    }
    
    return head;
  }
  
 private:
  inline bool allListTraversed(vector<ListNode*>& lists) {
    for (auto node : lists) {
      if (node) {
        return false;
      }
    }
    return true;
  }
  
  inline int incMinList(vector<ListNode*>& lists) {
    int minVal = 0;
    ListNode** minNode = nullptr;
    
    for (auto& node : lists) {
      if (!node) {
        continue;
      } else if (!minNode) {
        minNode = &node;
      } else if (node->val < (*minNode)->val) {
        minNode = &node;
      }
    }
    
    minVal = (*minNode)->val;
    *minNode = (*minNode)->next;
    return minVal;
  }
};
