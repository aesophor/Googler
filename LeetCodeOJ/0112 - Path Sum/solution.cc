// Runtime: 12 ms, faster than 75.46% of C++ online submissions for Path Sum.
// Memory Usage: 19.6 MB, less than 100.00% of C++ online submissions for Path Sum.

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
  bool hasPathSum(TreeNode* root, int sum) {
    if (!root) {
      return result_;
    }
    
    sum_ += root->val;
    if (!root->left && !root->right && sum_ == sum) {
      result_ = true;
      return true;
    }
    hasPathSum(root->left, sum);
    hasPathSum(root->right, sum);
    sum_ -= root->val; // backtrack
    
    return result_;
  }
  
 private:
  int sum_ = 0;
  bool result_ = false;
};
