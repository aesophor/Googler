#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;

struct TreeNode {
  TreeNode(int x) : val(x), children() {}
  int val;
  std::vector<TreeNode*> children;
};

class Codec {
 public:
  // Encodes a tree to a single string.
  std::string serialize(TreeNode* root) {
    if (!root) {
      return "";
    }
    
    std::string data;
    dfs(root, data);
    data.erase(data.rfind(",b,"));
    std::cout << "serialized: " << data << std::endl;
    return data;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(std::string data) {
    if (data.empty()) {
      return nullptr;
    }

    std::queue<std::string> val_queue;
    for (const auto& token : Split(data, ',')) {
      val_queue.push(token);
    }

    TreeNode* root = new TreeNode(std::stoi(val_queue.front()));
    TreeNode* current = root;
    val_queue.pop();

    std::stack<TreeNode*> st;
    st.push(root);

    while (!val_queue.empty()) {
      std::string val = val_queue.front();
      std::cout << val << std::endl;
      val_queue.pop();

      // Backtrack
      if (val == "b") {
        st.pop();
        current = st.top();
        continue;
      }

      TreeNode* new_node = new TreeNode(std::stoi(val));
      current->children.push_back(new_node);

      current = new_node;
      st.push(new_node);
    }
    
    return root;
  }
  
 private:
  void dfs(TreeNode* node, std::string& data) {
    if (!node) {
      return;
    }
    
    // Serialize current node.
    data += std::to_string(node->val) + ',';
    
    for (auto child : node->children) {
      dfs(child, data);
    }
    
    // Add 'b' which indicates when to backtrack
    // during deserialization.
    data += "b,";
  }

  vector<string> Split(const string& s, const char delimiter) {
    std::stringstream ss(s);
    string t;
    vector<string> tokens;

    while (std::getline(ss, t, delimiter)) {
      if (t.length() > 0) {
        tokens.push_back(t);
      }
    }
    return tokens;
  }
};


std::string& preOrder(TreeNode* node, std::string& result) {
  if (!node) {
    return result;
  }

  result += std::to_string(node->val) + ',';
  for (auto child : node->children) {
    preOrder(child, result);
  }
  return result;
}

std::string& postOrder(TreeNode* node, std::string& result) {
  if (!node) {
    return result;
  }

  for (auto child : node->children) {
    postOrder(child, result);
  }
  result += std::to_string(node->val) + ',';
  return result;
}


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
int main(int argc, char* args[]) {
  TreeNode* root1 = new TreeNode(2);
  root1->children.push_back(new TreeNode(1));
  root1->children.push_back(new TreeNode(3));
  root1->children.front()->children.push_back(new TreeNode(4));
  root1->children.front()->children.push_back(new TreeNode(5));

  TreeNode* root2 = nullptr;
  Codec codec;
  root2 = codec.deserialize(codec.serialize(root1));
  

  std::string tree1_preorder;
  std::string tree1_postorder;
  std::string tree2_preorder;
  std::string tree2_postorder;
  assert(preOrder(root1, tree1_preorder) == preOrder(root2, tree2_preorder));
  assert(postOrder(root1, tree1_postorder) == postOrder(root2, tree2_postorder));

  std::cout << "passed" << std::endl
    << "tree1 pre:" << tree1_preorder << std::endl
    << "tree2 pre:" << tree2_preorder << std::endl
    << "tree1 post:" << tree1_postorder << std::endl
    << "tree2 post:" << tree2_postorder << std::endl;
}
