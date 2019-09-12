// Runtime: 24 ms, faster than 86.17% of C++ online submissions for Binary Tree Tilt.
// Memory Usage: 22.1 MB, less than 42.68% of C++ online submissions for Binary Tree Tilt.

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
  int findTilt(TreeNode* root) {
    if (!root) {
      return _result;
    }
    
    _result += std::abs(sumTreeNodes(root->left) - sumTreeNodes(root->right));
    findTilt(root->left);
    findTilt(root->right);
    return _result;
  }
  
 private:
  int sumTreeNodes(TreeNode* node) {
    if (!node) {
      return 0;
    }
    
    return sumTreeNodes(node->left) + node->val + sumTreeNodes(node->right);
  }
  
  int _result;
};
