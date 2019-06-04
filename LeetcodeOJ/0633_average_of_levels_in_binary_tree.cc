// Runtime: 24 ms, faster than 83.27% of C++ online submissions for Average of Levels in Binary Tree.
// Memory Usage: 22 MB, less than 56.16% of C++ online submissions for Average of Levels in Binary Tree.

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
  vector<double> averageOfLevels(TreeNode* root) {
    if (!root) {
      return {};
    }
    
    vector<double> avgs;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int levelSize = q.size();
      double levelSum = 0;
      
      for (int i = 0; i < levelSize; i++) {
        TreeNode* node = q.front();
        q.pop();
        levelSum += node->val;
        
        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }
      avgs.push_back(levelSum / levelSize);
    }
    
    return avgs;
  }
};
