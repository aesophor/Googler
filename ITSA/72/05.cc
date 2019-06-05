#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

namespace {

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};  

unordered_map<int, int> inm;
vector<int> result;

TreeNode* dfs(vector<int>& preorder, int pleft, int pright, vector<int>& inorder, int ileft, int iright){
  if(pleft > pright) return nullptr;
  int val = preorder[pleft];
  TreeNode* root = new TreeNode(val);
  if(pleft == pright) return root;

  int iroot = inm[val], nleft = iroot - ileft;
  root->left = dfs(preorder, pleft + 1, pleft + nleft, inorder, ileft, iroot - 1);
  root->right = dfs(preorder, pleft + nleft + 1, pright, inorder, iroot + 1, iright);

  return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  int n = preorder.size(), i = 0;
  for(auto v: inorder) inm[v] = i++;

  return dfs(preorder, 0, n - 1, inorder, 0, n - 1);
}

void postOrder(TreeNode* node) {
  if (!node) {
    return;
  }
  postOrder(node->left);
  postOrder(node->right);
  result.push_back(node->val);
}

vector<int> split(const string& s, const char delimiter) {
  std::stringstream ss(s);
  string t;
  vector<int> tokens;

  while (std::getline(ss, t, delimiter)) {
    if (t.length() > 0) {
      tokens.push_back(std::stoi(t));
    }
  }
  return tokens;
}

} // namespace


int main() {
  string line1 = "";
  while (std::getline(cin, line1)) {
    string line2 = "";
    std::getline(cin, line2);

    vector<int> preOrder = ::split(line1, ' ');
    vector<int> inOrder = ::split(line2, ' ');
    TreeNode* root = buildTree(preOrder, inOrder);

    result.clear();
    postOrder(root);

    for (int i = 0; i < (int) result.size(); i++) {
      cout << result[i];
      if (i != (int) result.size() - 1) {
        cout << " ";
      }
    }
    cout << endl;
  }
}
