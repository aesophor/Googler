// Runtime: 4 ms, faster than 94.21% of C++ online submissions for Binary Tree Level Order Traversal.
// Memory Usage: 13.7 MB, less than 98.59% of C++ online submissions for Binary Tree Level Order Traversal.

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
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) {
      return {};
    }
    
    std::vector<std::vector<int>> result;
    std::queue<TreeNode*> q;
    
    q.push(root);
    while (!q.empty()) {
      size_t size = q.size();
      
      result.push_back({});
      
      for (size_t i = 0; i < size; i++) {
        TreeNode* node = q.front();
        result.back().push_back(node->val);
        q.pop();
        
        if (node->left) {
          q.push(node->left);
        }
        
        if (node->right) {
          q.push(node->right);
        }
      }
    }
    
    return result;
  }
};
