// Runtime: 452 ms, faster than 6.90% of C++ online submissions for Merge k Sorted Lists.
// Memory Usage: 11.4 MB, less than 94.36% of C++ online submissions for Merge k Sorted Lists.

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
    
    const int kListCount = lists.size();
    int selectors_idx[kListCount];
    ListNode* selectors[kListCount];
    int lists_remain = 0;
    
    for (int i = 0; i < kListCount; i++) {
      ListNode* head = lists.at(i);
      selectors_idx[i] = 0;
      selectors[i] = head;
      
      if (head) {
        lists_remain++;
      }
    }
    
    ListNode* new_head = nullptr;
    ListNode* new_current = nullptr;
    
    
    while (lists_remain > 0) {
      // Get the smallest element from k lists,
      // and increment the selector of that list.
      ListNode* min_node = nullptr;
      int min_node_idx = 0;
      for (int i = 0; i < kListCount; i++) {
        if (selectors[i]) {
          ListNode* current_node = selectors[i];
          if (!min_node) {
            min_node = current_node;
            min_node_idx = i;
          } else if (current_node->val < min_node->val) {
            min_node = current_node;
            min_node_idx = i;
          }
        }
      }
      selectors_idx[min_node_idx]++;
      selectors[min_node_idx] = selectors[min_node_idx]->next;
      
      if (!selectors[min_node_idx]) {
        lists_remain--;
      }
      
      // Create or append to the new list.
      ListNode* new_node = min_node;
      if (!new_head) {
        new_head = new_node;
      } else {
        new_current->next = new_node;
      }
      new_current = new_node;
    }
    
    return new_head;
  }
};
