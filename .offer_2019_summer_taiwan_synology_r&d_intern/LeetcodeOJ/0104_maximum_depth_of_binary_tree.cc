// Runtime: 12 ms, faster than 88.58% of C++ online submissions for Maximum Depth of Binary Tree.
// Memory Usage: 19.2 MB, less than 78.46% of C++ online submissions for Maximum Depth of Binary Tree.

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
  int maxDepth(TreeNode* root) {
    dfs(root);
    return _maxDepth;
  }
 
 private:
  void dfs(TreeNode* node) {
    if (!node) {
      return;
    }
    
    _depth++;
    _maxDepth = std::max(_maxDepth, _depth);
    
    dfs(node->left);
    dfs(node->right);
    
    _depth--;
  }
  
  int _depth = 0;
  int _maxDepth = 0;
};
