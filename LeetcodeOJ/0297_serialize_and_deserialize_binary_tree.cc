// Runtime: 32 ms, faster than 92.31% of C++ online submissions for Serialize and Deserialize Binary Tree.
// Memory Usage: 28.7 MB, less than 44.83% of C++ online submissions for Serialize and Deserialize Binary Tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
 public:
  // Encodes a tree to a single string.
  std::string serialize(TreeNode* root) {
    if (!root) {
      return "";
    }
    
    std::string data;
    serializeDfs(root, data);
    if (data.back() == ',') {
      data.pop_back();
    }
    return data;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(std::string data) {
    if (data.empty()) {
      return nullptr;
    }
    
    std::queue<std::string> nodes = split(data, ',');
    TreeNode* root = nullptr;
    deserializeDfs(root, nodes);
    return root;
  }
  
 private:
  void serializeDfs(TreeNode* node, std::string& data) {
    if (!node) {
      data += "x,";
      return;
    }
    
    // Serialize current node.
    data += std::to_string(node->val) + ',';
    
    serializeDfs(node->left, data);
    serializeDfs(node->right, data);   
  }
  
  void deserializeDfs(TreeNode*& node, std::queue<std::string>& nodes) {
    if (nodes.empty()) {
      return;
    }
    
    std::string next_val = nodes.front();
    nodes.pop();
    if (next_val == "x") {
      return;
    }
    
    node = new TreeNode(std::stoi(next_val));
    deserializeDfs(node->left, nodes);
    deserializeDfs(node->right, nodes);
  }
  
  std::queue<std::string> split(const std::string& s, const char delimiter) {
    std::stringstream ss(s);
    std::string t;
    std::queue<std::string> tokens;

    while (std::getline(ss, t, delimiter)) {
      if (t.length() > 0) {
        tokens.push(t);
      }
    }
    return tokens;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
