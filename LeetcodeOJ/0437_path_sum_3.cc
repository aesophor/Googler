// Runtime: 16 ms, faster than 97.19% of C++ online submissions for Path Sum III.
// Memory Usage: 14.7 MB, less than 75.85% of C++ online submissions for Path Sum III.

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
  int pathSum(TreeNode* root, int sum) {
    if (!root) {
      return 0;
    }
    
    dfs(root, sum);
    pathSum(root->left, sum);
    pathSum(root->right, sum);
    return _result;
  }
  
 private:
  void dfs(TreeNode* node, int sum) {
    if (!node) {
      return;
    }
    
    _sum += node->val;
    if (_sum == sum) {
      _result++;
    }
    
    dfs(node->left, sum);
    dfs(node->right, sum);
    
    _sum -= node->val;
  }
  
  int _result = 0;
  int _sum = 0;
};
