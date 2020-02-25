// Runtime: 16 ms, faster than 44.14% of C++ online submissions for Minimum Depth of Binary Tree.
// Memory Usage: 19.4 MB, less than 100.00% of C++ online submissions for Minimum Depth of Binary Tree.

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
    return min_depth_;
  }
  
 private:
  void dfs(TreeNode* node) {
    if (!node) {
      return;
    }
    
    current_depth_++;
    if (!node->left && !node->right) {
      min_depth_ = std::min(min_depth_, current_depth_);
    }
    
    dfs(node->left);
    dfs(node->right);
    
    current_depth_--;  // backtrack
  }
  
  int current_depth_ = 0;
  int min_depth_ = INT_MAX;
};
