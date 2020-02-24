// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Preorder Traversal.
// Memory Usage: 11.5 MB, less than 5.17% of C++ online submissions for Binary Tree Preorder Traversal.

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
  vector<int> preorderTraversal(TreeNode* root) {
    if (!root) {
      return result_;
    }
    
    result_.push_back(root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    return result_;
  }
  
 private:
  std::vector<int> result_;
};
