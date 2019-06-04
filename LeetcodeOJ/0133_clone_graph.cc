// Runtime: 20 ms, faster than 98.41% of C++ online submissions for Clone Graph.
// Memory Usage: 17 MB, less than 5.22% of C++ online submissions for Clone Graph.

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
    dfs(node);
    return _m[node];
  }
  
 private:
  void dfs(Node* node) {
    if (_m.find(node) != _m.end()) {
      return;
    }
    
    Node* newNode = new Node();
    _m.insert({node, newNode});
    newNode->val = node->val;
    
    for (auto neighbor : node->neighbors) {
      dfs(neighbor);
      newNode->neighbors.push_back(_m[neighbor]);
    }
  }
  
  unordered_map<Node*, Node*> _m;
};
