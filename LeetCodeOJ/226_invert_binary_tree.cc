// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Invert Binary Tree.
// Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for Invert Binary Tree.

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
  TreeNode* invertTree(TreeNode* root) {
    swapChildren(root);
    return root;
  }
  
private:
  void swapChildren(TreeNode* node) {
    if (!node) {
      return;
    }
    std::swap(node->left, node->right);
    swapChildren(node->left);
    swapChildren(node->right);
  }
};
