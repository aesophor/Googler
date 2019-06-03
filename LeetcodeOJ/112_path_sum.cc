// Runtime: 16 ms, faster than 84.44% of C++ online submissions for Path Sum.
// Memory Usage: 20 MB, less than 12.65% of C++ online submissions for Path Sum.

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
    dfs(root, sum);
    return _result;
  }
  
 private:
  void dfs(TreeNode* node, int sum) {
    if (!node) {
      return;
    }
    
    _sum += node->val;
    if (!node->left && !node->right) {
      if (_sum == sum) {
        _result = true;
      }
    }
    
    dfs(node->left, sum);
    dfs(node->right, sum);
    
    _sum -= node->val;
  }
  
  int _sum = 0;
  bool _result = false;
};
