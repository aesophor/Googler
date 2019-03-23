// Runtime: 24 ms, faster than 82.81% of C++ online submissions for Find Largest Value in Each Tree Row.
// Memory Usage: 21.3 MB, less than 96.81% of C++ online submissions for Find Largest Value in Each Tree Row.

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
  vector<int> largestValues(TreeNode* root) {
    if (!root) {
      return {};
    }
    
    vector<int> result; // max values of each tree row
    int current_max = INT_MIN;
    
    // BFS and find max element on each tree row
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        current_max = std::max(current_max, q.front()->val);
        
        // Push its child(ren) at the end of the queue.
        if (q.front()->left) {
          q.push(q.front()->left);
        }
        if (q.front()->right) {
          q.push(q.front()->right);
        }
        
        q.pop();
      }
      
      result.push_back(current_max);
      current_max = INT_MIN;
    }
    
    return result;
  }
};
