// Runtime: 36 ms, faster than 87.32% of C++ online submissions for Delete Node in a BST.
// Memory Usage: 13 MB, less than 97.95% of C++ online submissions for Delete Node in a BST.

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return nullptr;
        }
        
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else { // equals
            // Four situations:
            // 1. 這個 node 爲樹葉 -> 直接反回 nullptr, 清除 parent 對它的連結
            // 2. 只有 left subtree -> 返回 right subtree
            // 3. 只有 right subtree -> 返回 left subtree
            // 4. 有 left/right subtrees -> 見下方 else block
            if (!root->left && !root->right) {
                return nullptr;
            } else if (root->left && !root->right) {
                return root->left;
            } else if (!root->left && root->right) {
                return root->right;
            } else {
                // Two choices:
                // 1. 找 right subtree min value 取代此 node
                // 2. 找 left subtree max value 取代此 node
                // 然後刪除那個 node~~
                root->val = findMaximumNode(root->left);
                root->left = deleteNode(root->left, root->val);
            }
        }
        
        return root;
    }
    
private:
    inline int findMaximumNode(TreeNode* node) {
        int max_val = node->val;
        while (node) {
            max_val = std::max(max_val, node->val);
            node = node->right;
        }
        return max_val;
    }
};
