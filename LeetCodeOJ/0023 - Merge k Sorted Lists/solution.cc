// Runtime: 324 ms, faster than 12.23% of C++ online submissions for Merge k Sorted Lists.
// Memory Usage: 11.3 MB, less than 52.38% of C++ online submissions for Merge k Sorted Lists.

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
    
    ListNode* head = nullptr;
    ListNode* current = nullptr;
    
    while (!isAllListTraversed(lists)) {
      ListNode*& ptr = getNextNode(lists);
     
      ListNode* newNode = new ListNode(ptr->val);
      if (!head) {
        head = newNode;
      } else {
        current->next = newNode;
      }
      current = newNode;
      
      ptr = ptr->next;
    }

    return head;
  }
  
 private:
  bool isAllListTraversed(vector<ListNode*>& lists) {
    for (auto node : lists) {
      if (node) {
        return false;
      }
    }
    return true;
  }
  
  ListNode*& getNextNode(vector<ListNode*>& lists) {
    int minVal = 0;
    ListNode** minNode = nullptr;
    
    for (auto& node : lists) {
      if (!node) {
        continue;
      }
      minVal = node->val;
      minNode = &node;
      break;
    }
    
    for (auto& node : lists) {
      if (!node) {
        continue;
      }
      
      if (node->val < minVal) {
        minVal = node->val;
        minNode = &node;
      }
    }
    
    return *minNode; // ret by ref
  }
};
