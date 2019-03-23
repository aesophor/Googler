// Runtime: 36 ms, faster than 99.96% of C++ online submissions for Copy List with Random Pointer.
// Memory Usage: 22 MB, less than 5.21% of C++ online submissions for Copy List with Random Pointer.

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
    unordered_map<Node*, Node*> old_to_new;
    
    Node* new_head = nullptr;
    Node* prev = nullptr;
    Node* ptr = head;
    while (ptr) {
      Node* new_node = new Node(ptr->val, nullptr, ptr->random);
      old_to_new[ptr] = new_node;
      
      // If the new head hasn't been set, set it.
      if (!new_head) {
        new_head = new_node;
      }
      // Set the previous node's next pointer to this node.
      if (prev) {
        prev->next = new_node;
      }
      
      prev = new_node;
      ptr = ptr->next;
    }
    
    // deep copy the random pointers.
    ptr = new_head;
    while (ptr) {
      if (ptr->random) {
        ptr->random = old_to_new.at(ptr->random);
      }
      ptr = ptr->next;
    }
    
    return new_head;
  }
};

// 1->2->3->nullptr
