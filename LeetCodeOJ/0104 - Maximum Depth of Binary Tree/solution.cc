// Runtime: 8 ms, faster than 87.61% of C++ online submissions for Maximum Depth of Binary Tree.
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
    if (!root) {
      return 0;
    }
    
    current_++;
    if (!root->left && !root->right) {
      result_ = std::max(result_, current_);
    }
    maxDepth(root->left);
    maxDepth(root->right);
    current_--; // backtrack
    
    return result_;
  }
  
 private:
  int current_ = 0;
  int result_ = 0;
};
