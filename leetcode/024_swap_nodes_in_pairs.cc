// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Swap Nodes in Pairs.
// Memory Usage: 8.9 MB, less than 66.92% of C++ online submissions for Swap Nodes in Pairs.

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
    ListNode* swapPairs(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        
        pair<ListNode*, ListNode*> current_pair = { head, head->next }; // in original order
        ListNode* ret = (current_pair.second) ? current_pair.second : current_pair.first;
        
        while (current_pair.first) {
            if (!current_pair.second) {
                break;
            }
            
            // Cache the next pair if it exists.
            pair<ListNode*, ListNode*> next_pair = { nullptr, nullptr };
            
            if (current_pair.second) {
                next_pair.first = current_pair.second->next;
                if (current_pair.second->next) {
                    next_pair.second = current_pair.second->next->next;
                }
            }
            
            if (next_pair.first && !next_pair.second) {
                current_pair.second->next = current_pair.first;
                current_pair.first->next = next_pair.first;
                break;
            }
            
            // Re-link current pair
            current_pair.second->next = current_pair.first;
            current_pair.first->next = next_pair.second;
            
            current_pair.second = next_pair.second;
            current_pair.first = next_pair.first;
        }
        
        return ret;
    }
};
