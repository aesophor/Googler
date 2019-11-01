// Runtime: 12 ms, faster than 76.02% of C++ online submissions for Minimum Depth of Binary Tree.
// Memory Usage: 19.5 MB, less than 97.62% of C++ online submissions for Minimum Depth of Binary Tree.

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
    
    current_++;
    if (!root->left && !root->right) {
      result_ = std::min(result_, current_);
    }
    minDepth(root->left);
    minDepth(root->right);
    current_--; // backtrack
    
    return result_;
  }
  
 private:
  int current_ = 0;
  int result_ = INT_MAX;
};
