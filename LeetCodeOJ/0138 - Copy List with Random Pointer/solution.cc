// Runtime: 32 ms, faster than 74.37% of C++ online submissions for Copy List with Random Pointer.
// Memory Usage: 21.9 MB, less than 100.00% of C++ online submissions for Copy List with Random Pointer.

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
    if (!head) {
      return nullptr;
    }
    
    std::unordered_map<Node*, Node*> mapper_; // old to new
    
    Node* newHead = nullptr;
    Node* newCurrent = nullptr;
    Node* current = head;
    
    while (current) {
      Node* newNode = new Node(current->val, nullptr, nullptr);
      mapper_[current] = newNode;
      
      if (!newHead) {
        newHead = newNode;
      }
      if (newCurrent) {
        newCurrent->next = newNode;
      }
      newCurrent = newNode;
      
      current = current->next;
    }
    
    
    // Handle the god damn random pointer
    current = head;
    while (current) {
      Node* newNode = mapper_[current];
      
      if (current->random) {
        newNode->random = mapper_[current->random];
      }
      
      current = current->next;
    }
    
    return newHead;
  }
};
