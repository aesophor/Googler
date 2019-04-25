// Runtime: 16 ms, faster than 99.46% of C++ online submissions for Minimum Depth of Binary Tree.
// Memory Usage: 19.5 MB, less than 90.18% of C++ online submissions for Minimum Depth of Binary Tree.

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
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        traverse(root, 1);
        return minimum_depth_;
    }
    
private:
    void traverse(TreeNode* node, int level) {
        if (!node) {
            return;
        }
        
        if (!node->left && !node->right) {
            if (!found_first_) {
                minimum_depth_ = level;
                found_first_ = true;
            } else {
                minimum_depth_ = std::min(minimum_depth_, level);
            }
        }
        traverse(node->left, level + 1);
        traverse(node->right, level + 1);
    }
    
    bool found_first_ = false;
    int minimum_depth_ = 0;
};
