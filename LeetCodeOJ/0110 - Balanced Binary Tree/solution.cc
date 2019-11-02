// Runtime: 12 ms, faster than 84.52% of C++ online submissions for Balanced Binary Tree.
// Memory Usage: 16.3 MB, less than 100.00% of C++ online submissions for Balanced Binary Tree.

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
  bool isBalanced(TreeNode* root) {
    if (!root) {
      return result_;
    }
    
    current_height_ = max_height_ = 0;
    int left_h = getHeight(root->left);
    
    current_height_ = max_height_ = 0;
    int right_h = getHeight(root->right);
    
    if (std::abs(left_h - right_h) > 1) {
      result_ = false;
      return false;
    }
    isBalanced(root->left);
    isBalanced(root->right);
    
    return result_;
  }
  
 private:
  // Tree DFS
  int getHeight(TreeNode* node) {
    if (!node) {
      return max_height_;
    }
    
    current_height_++;
    if (!node->left && !node->right) {
      max_height_ = std::max(max_height_, current_height_);
    }
    getHeight(node->left);
    getHeight(node->right);
    current_height_--; // backtrack
    
    return max_height_;
  }
  
  // For a subtree
  int current_height_ = 0;
  int max_height_ = 0;

  bool result_ = true;
};
