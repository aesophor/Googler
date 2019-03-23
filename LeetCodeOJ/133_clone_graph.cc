// Runtime: 28 ms, faster than 99.89% of C++ online submissions for Clone Graph.
// Memory Usage: 16.8 MB, less than 64.40% of C++ online submissions for Clone Graph.

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
    depthFirstSearch(node);
    return mapper_.at(node);
  }
  
private:
  void depthFirstSearch(Node* node) {
    if (mapper_.find(node) != mapper_.end()) {
      return;
    }
    
    // Clone this node and store it in hashmap
    Node* new_node = new Node(node->val);
    mapper_[node] = new_node;
    
    // Recursively clone neighbors
    for (auto neighbor : node->neighbors) {
      depthFirstSearch(neighbor);
      new_node->neighbors.push_back(mapper_.at(neighbor));
    }
  }
  
  unordered_map<Node*, Node*> mapper_;
};
