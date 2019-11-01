// Runtime: 20 ms, faster than 94.54% of C++ online submissions for Clone Graph.
// Memory Usage: 16.9 MB, less than 40.00% of C++ online submissions for Clone Graph.

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (!node) {
      return nullptr;
    }
    
    helper(node);
    return mapper_[node];
  }
  
 private:
  void helper(Node* node) {
    if (!node || mapper_.find(node) != mapper_.end()) {
      return;
    }
    
    Node* newNode = new Node(node->val, {});
    mapper_[node] = newNode;
    
    for (auto neighbor : node->neighbors) {
      helper(neighbor);
      newNode->neighbors.push_back(mapper_[neighbor]);
    }
  }
  
  std::unordered_map<Node*, Node*> mapper_; // old to new
};
