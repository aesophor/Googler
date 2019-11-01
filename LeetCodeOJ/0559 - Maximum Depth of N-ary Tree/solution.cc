// Runtime: 140 ms, faster than 81.28% of C++ online submissions for Maximum Depth of N-ary Tree.
// Memory Usage: 31.8 MB, less than 100.00% of C++ online submissions for Maximum Depth of N-ary Tree.

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
    if (!root) {
      return 0;
    }
    
    current_++;
    if (root->children.empty()) {
      result_ = std::max(result_, current_);
    }
    for (auto child : root->children) {
      maxDepth(child);
    }
    current_--; // backtrack
    
    return result_;
  }
  
 private:
  int current_ = 0;
  int result_ = 0;
};
