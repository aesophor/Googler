// Runtime: 12 ms, faster than 97.02% of C++ online submissions for Validate Binary Search Tree.
// Memory Usage: 20.8 MB, less than 21.63% of C++ online submissions for Validate Binary Search Tree.

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
  bool isValidBST(TreeNode* root) {
    if (!root) {
      return true;
    }
    
    return isValidBST(root->left)
      && isNodeLessThan(root->left, root->val)
      && isNodeGreaterThan(root->right, root->val)
      && isValidBST(root->right);
  }
  
 private:
  bool isNodeLessThan(TreeNode* node, const int n) {
    if (!node) {
      return true;
    }
    
    if (node->val >= n) {
      return false;
    }
    return isNodeLessThan(node->left, n)
      && isNodeLessThan(node->right, n);
  }
  
  bool isNodeGreaterThan(TreeNode* node, const int n) {
    if (!node) {
      return true;
    }
    
    if (node->val <= n) {
      return false;
    }
    return isNodeGreaterThan(node->left, n)
      && isNodeGreaterThan(node->right, n);
  }
};
