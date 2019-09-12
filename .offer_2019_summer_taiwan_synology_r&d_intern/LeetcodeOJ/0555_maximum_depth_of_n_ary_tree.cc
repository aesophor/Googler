// Runtime: 128 ms, faster than 99.65% of C++ online submissions for Maximum Depth of N-ary Tree.
// Memory Usage: 32.2 MB, less than 34.56% of C++ online submissions for Maximum Depth of N-ary Tree.

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
 public:
  int maxDepth(Node* root) {
    dfs(root);
    return _maxDepth;
  }
  
 private:
  void dfs(Node* node) {
    if (!node) {
      return;
    }
    
    _maxDepth = std::max(_maxDepth, ++_depth);
    for (auto child : node->children) {
      dfs(child);
    }
    _depth--;
  }
  
  int _depth = 0;
  int _maxDepth = 0;
};
