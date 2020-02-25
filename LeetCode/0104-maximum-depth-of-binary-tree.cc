// Runtime: 4 ms, faster than 98.71% of C++ online submissions for Maximum Depth of Binary Tree.
// Memory Usage: 19.1 MB, less than 98.90% of C++ online submissions for Maximum Depth of Binary Tree.

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
    return max_depth_;
  }
  
 private:
  void dfs(TreeNode* node) {
    if (!node) {
      return;
    }
    
    current_depth_++;
    max_depth_ = std::max(max_depth_, current_depth_);
    
    dfs(node->left);
    dfs(node->right);

    current_depth_--;
  }
  
  int current_depth_ = 0;
  int max_depth_ = 0;
};
