// Runtime: 4 ms, faster than 95.28% of C++ online submissions for Binary Tree Level Order Traversal II.
// Memory Usage: 13.8 MB, less than 97.30% of C++ online submissions for Binary Tree Level Order Traversal II.

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
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if (!root) {
      return {};
    }
    
    std::vector<std::vector<int>> result;
    std::queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
      size_t qSize = q.size();
      result.push_back({});
      
      for (size_t i = 0; i < qSize; i++) {
        TreeNode* node = q.front();
        q.pop();
        result.back().push_back(node->val);

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);   
      }
    }
    
    std::reverse(result.begin(), result.end());
    return result;
  }
};
