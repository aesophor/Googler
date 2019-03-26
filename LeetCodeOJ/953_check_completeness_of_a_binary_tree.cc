// Runtime: 8 ms, faster than 99.53% of C++ online submissions for Check Completeness of a Binary Tree.
// Memory Usage: 10 MB, less than 100.00% of C++ online submissions for Check Completeness of a Binary Tree.

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
  bool isCompleteTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    bool detected_empty_node = false;
    
    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();
      
      if (!node) {
        detected_empty_node = true;
        continue;
      }
      
      // If we have already detected an empty node,
      // but we still detected another concrete node afterwards,
      // then this tree is not a complete binary tree.
      if (detected_empty_node && node) {
        return false;
      }
      
      q.push(node->left);
      q.push(node->right);
    }
    
    return true;
  }
};
