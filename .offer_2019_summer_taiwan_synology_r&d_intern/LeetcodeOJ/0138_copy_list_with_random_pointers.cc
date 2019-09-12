// Runtime: 32 ms, faster than 94.11% of C++ online submissions for Copy List with Random Pointer.
// Memory Usage: 22.3 MB, less than 12.05% of C++ online submissions for Copy List with Random Pointer.

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
 public:
  Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> m;
    
    Node* prev = nullptr;
    Node* ptr = head;
    while (ptr) {
      Node* newNode = new Node(0, nullptr, nullptr);
      m.insert({ptr, newNode});
      newNode->val = ptr->val;
      if (prev) {
        prev->next = newNode;
      }
      prev = newNode;
      ptr = ptr->next;
    }
    
    ptr = head;
    while (ptr) {
      if (ptr->random) {
        m[ptr]->random = m[ptr->random];
      }
      ptr = ptr->next;
    }
    
    return m[head];
  }
};
