// Runtime: 96 ms, faster than 96.93% of C++ online submissions for Insert into a Binary Search Tree.
// Memory Usage: 32.8 MB, less than 99.54% of C++ online submissions for Insert into a Binary Search Tree.

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* current = root;
        
        while (current) {
            if (current->val < val) {
                // Check if right child is empty, if yes we can insert it there.
                if (current->right) {
                    current = current->right;
                } else {
                    current->right = new TreeNode(val);
                    break;
                }
            } else if (current->val > val) {
                // Check if left child is empty, if yes we can insert it there.
                if (current->left) {
                    current = current->left;
                } else {
                    current->left = new TreeNode(val);
                    break;
                }
            }
        }
        
        return root;
    }
};
