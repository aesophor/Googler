// Runtime: 8 ms, faster than 82.43% of C++ online submissions for Sum of Left Leaves.
// Memory Usage: 13.7 MB, less than 50.47% of C++ online submissions for Sum of Left Leaves.

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
  int sumOfLeftLeaves(TreeNode* root) {
    dfs(root);
    return _result;
  }
  
 private:
  void dfs(TreeNode* node) {
    if (!node || (!node->left && !node->right)) {
      return;
    }
    
    if (node->left && isLeaf(node->left)) {
      _result += node->left->val;
    }
    dfs(node->left);
    dfs(node->right);
  }
  
  inline bool isLeaf(TreeNode* node) {
    return !node->left && !node->right;
  }
  
  int _result = 0;
};
