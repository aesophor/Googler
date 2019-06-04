// Runtime: 24 ms, faster than 86.77% of C++ online submissions for Kth Smallest Element in a BST.
// Memory Usage: 21.6 MB, less than 53.64% of C++ online submissions for Kth Smallest Element in a BST.

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
  int kthSmallest(TreeNode* root, int k) {
    dfs(root, k);
    return _lastMin;
  }

 private:
  void dfs(TreeNode* node, const int k) {
    if (!node || _count == k) {
      return;
    }
    
    dfs(node->left, k);
    
    if (!_lastMinInit) {
      _lastMin = node->val;
      _lastMinInit = true;
      _count = 1;
    } else if (node->val > _lastMin && _count < k) {
      _lastMin = node->val;
      _count++;
    }
    
    dfs(node->right, k);
  }
  
  bool _lastMinInit = false;
  int _lastMin = 0;
  int _count = 0;
};
