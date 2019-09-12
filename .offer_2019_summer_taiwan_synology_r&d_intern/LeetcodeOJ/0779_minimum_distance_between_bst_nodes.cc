// Runtime: 4 ms, faster than 91.91% of C++ online submissions for Minimum Distance Between BST Nodes.
// Memory Usage: 11.6 MB, less than 19.15% of C++ online submissions for Minimum Distance Between BST Nodes.

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
  int minDiffInBST(TreeNode* root) {
    if (!root) {
      return _min;
    }
    
    minDiffInBST(root->left);
    
    getMinDiff(root->left, root->val);
    getMinDiff(root->right, root->val);
    
    minDiffInBST(root->right);
    return _min;
  }
  
 private:
  void getMinDiff(TreeNode* node, const int val) {
    if (!node) {
      return;
    }
    
    getMinDiff(node->left, val);
    _min = std::min(_min, std::abs(node->val - val));
    getMinDiff(node->right, val);
  }
  
  int _min = INT_MAX;
};
