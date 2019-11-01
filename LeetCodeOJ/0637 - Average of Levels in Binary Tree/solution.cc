// Runtime: 12 ms, faster than 98.60% of C++ online submissions for Average of Levels in Binary Tree.
// Memory Usage: 22.2 MB, less than 33.33% of C++ online submissions for Average of Levels in Binary Tree.

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
    
    std::vector<vector<long long>> levels;
    std::vector<double> averages;
    std::queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
      levels.push_back({});
      size_t qSize = q.size();
      
      for (size_t i = 0; i < qSize; i++) {
        TreeNode* node = q.front();
        q.pop();
        levels.back().push_back(node->val);
        
        if (node->left) { q.push(node->left); }
        if (node->right) { q.push(node->right); }
      }
    }
    
    for (const auto& level : levels) {
      long long sum = 0;
      for (auto num : level) {
        sum += num;
      }
      averages.push_back((double) sum / level.size());
    }
    
    return averages;
  }
};
