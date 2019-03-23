// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Binary Tree Paths.
// Memory Usage: 12.3 MB, less than 84.30% of C++ online submissions for Binary Tree Paths.

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
  vector<string> binaryTreePaths(TreeNode* root) {
    preOrder(root);
    return result_;
  }
  
private:
  void preOrder(TreeNode* node) {
    if (!node) {
      return;
    }
    
    path_.push_back(node->val);
    if (!node->left && !node->right) {
      appendPath();
    }
    preOrder(node->left);
    preOrder(node->right);
    path_.pop_back(); // Backtracking
  }
  
  inline void appendPath() {
    string path_str;
    for (int i = 0; i < path_.size(); i++) {
      path_str += std::to_string(path_.at(i));
      if (i != path_.size() - 1) {
        path_str += "->";
      }
    }
    result_.push_back(path_str);
  }
  
  vector<int> path_;
  vector<string> result_;
};
