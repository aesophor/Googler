// Runtime: 16 ms, faster than 79.65% of C++ online submissions for Minimum Depth of Binary Tree.
// Memory Usage: 19.6 MB, less than 75.37% of C++ online submissions for Minimum Depth of Binary Tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (!root) {
      return 0;
    }
    
    dfs(root);
    return _minDepth;
  }
  
 private:
  void dfs(TreeNode* node) {
    if (!node) {
      return;
    }
    
    _currentDepth++;
    if (!node->left && !node->right) {
      _minDepth = std::min(_minDepth, _currentDepth);
    }
    dfs(node->left);
    dfs(node->right);
    _currentDepth--;
  }
  
  int _minDepth = INT_MAX;
  int _currentDepth = 0;
};
