// Runtime: 4 ms, faster than 98.12% of C++ online submissions for Binary Tree Level Order Traversal.
// Memory Usage: 14.1 MB, less than 30.33% of C++ online submissions for Binary Tree Level Order Traversal.

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
    
    vector<vector<int>> result;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int levelSize = q.size();
      
      vector<int> level;
      for (int i = 0; i < levelSize; i++) {
        TreeNode* node = q.front();
        q.pop();
        level.push_back(node->val);
        
        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }
      result.push_back(level);
    }
    return result;
  }
};
