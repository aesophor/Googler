// Runtime: 52 ms, faster than 97.87% of C++ online submissions for Intersection of Two Linked Lists.
// Memory Usage: 16.6 MB, less than 95.53% of C++ online submissions for Intersection of Two Linked Lists.

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
        int sizeA = getSize(headA);
        int sizeB = getSize(headB);
        int diff = std::abs(sizeA - sizeB);
        
        if (sizeA > sizeB) {
            for (int i = 0; i < diff; i++) {
                headA = headA->next;
            }
        } else if (sizeA < sizeB) {
            for (int i = 0; i < diff; i++) {
                headB = headB->next;
            }
        }
        
        ListNode* intersectBegin = nullptr;
        while (headA && headB) {
            if (headA == headB) { // 所謂 intersection 是碰到一樣的node, 不是內容一樣就算。。。
                intersectBegin = headA;
                break;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return intersectBegin;
    }
    
    inline int getSize(ListNode* head) {
        int size = 0;
        while (head) {
            head = head->next;
            size++;
        }
        return size;
    }
};
