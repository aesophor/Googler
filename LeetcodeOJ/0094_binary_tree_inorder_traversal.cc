// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
// Memory Usage: 9.7 MB, less than 10.98% of C++ online submissions for Binary Tree Inorder Traversal.

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
  vector<int> inorderTraversal(TreeNode* root) {
    inOrder(root);
    return _result;
  }
  
 private:
  void inOrder(TreeNode* node) {
    if (!node) {
      return;
    }
    
    inOrder(node->left);
    _result.push_back(node->val);
    inOrder(node->right);
  }
  
  vector<int> _result;
};
