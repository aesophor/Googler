// Runtime: 148 ms, faster than 93.66% of C++ online submissions for N-ary Tree Level Order Traversal.
// Memory Usage: 33.9 MB, less than 52.20% of C++ online submissions for N-ary Tree Level Order Traversal.

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
  vector<vector<int>> levelOrder(Node* root) {
    if (!root) {
      return {};
    }
    
    vector<vector<int>> result;
    
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
      int qSize = q.size();
      
      vector<int> level;
      for (int i = 0; i < qSize; i++) {
        Node* node = q.front();
        q.pop();
        level.push_back(node->val);
        
        for (auto child : node->children) {
          q.push(child);
        }
      }
      result.push_back(level);
    }
    return result;
  }
};
