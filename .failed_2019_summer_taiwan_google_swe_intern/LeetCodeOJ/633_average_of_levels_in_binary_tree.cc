// Runtime: 28 ms, faster than 67.80% of C++ online submissions for Average of Levels in Binary Tree.
// Memory Usage: 22.1 MB, less than 77.88% of C++ online submissions for Average of Levels in Binary Tree.

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
        vector<double> avg;
        if (!root) {
            return avg;
        }
        
        vector<int> current_level;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            current_level.clear();
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                current_level.push_back(q.front()->val);
                
                if (q.front()->left) {
                    q.push(q.front()->left);
                }
                if (q.front()->right) {
                    q.push(q.front()->right);
                }
                
                q.pop();
            }
            
            // Calculate avg of current_level
            double sum = 0;
            for (auto val : current_level) {
                sum += val;
            }
            avg.push_back(sum / current_level.size());
        }
        
        return avg;
    }
};
