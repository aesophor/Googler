// Runtime: 4 ms, faster than 88.95% of C++ online submissions for Invert Binary Tree.
// Memory Usage: 9.2 MB, less than 30.82% of C++ online submissions for Invert Binary Tree.

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
    if (!root) {
      return root;
    }
    
    swapChildren(root);
    invertTree(root->left);
    invertTree(root->right);
    return root;
  }
  
 private:
  void swapChildren(TreeNode* node) {
    TreeNode* temp = node->left;
    node->left = node->right;
    node->right = temp;
  }
};
