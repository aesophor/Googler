// Runtime: 4 ms, faster than 61.57% of C++ online submissions for Same Tree.
// Memory Usage: 10.5 MB, less than 5.55% of C++ online submissions for Same Tree.

// 遇到空的節點, 記得 push_back(0)
//
// 因爲：
//         1 1
//        /   \
//       1     1
//
// 沒加0
//  pre:  11   11
//  in :  11   11
//
// 有加0
//  pre: 110  101
//  in : 110  011

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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    std::vector<int> result1;
    std::vector<int> result2;
    
    preOrder(p, result1);
    preOrder(q, result2);
    
    if (result1 != result2) {
      return false;
    }
    
    
    result1.clear();
    result2.clear();
    
    inOrder(p, result1);
    inOrder(q, result2);
    
    return result1 == result2;
  }
  
 private:
  void preOrder(TreeNode* node, std::vector<int>& result) {
    if (!node) {
      result.push_back(0);
      return;
    }
    
    result.push_back(node->val);
    preOrder(node->left, result);
    preOrder(node->right, result);
  }
  
  void inOrder(TreeNode* node, std::vector<int>& result) {
    if (!node) {
      result.push_back(0);
      return;
    }
    
    inOrder(node->left, result);
    result.push_back(node->val);
    inOrder(node->right, result);
  }
};
