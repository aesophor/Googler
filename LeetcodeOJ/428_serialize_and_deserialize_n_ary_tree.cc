#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <stack>

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
    std::cout << "serialized: " << data << std::endl;
    return data;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(std::string data) {
    if (data.empty()) {
      return nullptr;
    }
    
    TreeNode* root = nullptr;
    TreeNode* current = nullptr;
    std::stack<TreeNode*> st;
    
    do {
      // Backtrack if 'b' is seen at the front of data.
      if (data.front() == 'b') {
        data.erase(0, 1);
        st.pop();
        current = st.top();
        continue;
      }
      
      // Extract next value and erase the
      // processed characters from the data string.
      size_t delim_pos = data.find_first_of(",b");
      int val = std::stoi(data.substr(0, delim_pos));
      
      bool backtrack = data[delim_pos] == 'b';
      data.erase(0, delim_pos + 1); // including the delimiter (, or b)
      
      TreeNode* new_node = new TreeNode(val);
      if (!root) {
        root = new_node;
      } else {
        current->children.push_back(new_node);
      }

      if (!backtrack) {
        current = new_node;
        st.push(new_node);   
      }
    } while (data.size() > 1);
    
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
    
    // Backtrack
    if (data.back() == ',') {
      data.pop_back();
    }
    data.push_back('b');
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
