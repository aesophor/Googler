// Runtime: 16 ms, faster than 99.08% of C++ online submissions for Maximum Depth of Binary Tree.
// Memory Usage: 19.4 MB, less than 57.53% of C++ online submissions for Maximum Depth of Binary Tree.

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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        traverse(root, 1);
        return max_depth_;
    }
    
private:
    void traverse(TreeNode* node, int level) {
        if (!node) {
            return;
        }
        
        max_depth_ = std::max(max_depth_, level);
        traverse(node->left, level + 1);
        traverse(node->right, level + 1);
    }
        
    int max_depth_ = 0;
};
