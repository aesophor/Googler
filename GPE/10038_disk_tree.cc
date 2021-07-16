#include <bits/stdc++.h>

using namespace std;

class Node {
 public:
  Node(const string& name) : _name(name) {}

  Node* get_or_create_child(const string& name) {
    // If the child already exists, return it.
    for (int i = 0; i < (int) _children.size(); i++) {
      if (_children[i]->_name == name) {
        return _children[i];
      }
    }

    // Otherwise, create and return it.
    Node* child = new Node(name);
    _children.push_back(child);
    return child;
  }

  string _name;
  vector<Node*> _children;
};

struct cmp {
  bool operator ()(Node* n1, Node* n2) {
    return n1->_name < n2->_name;
  }
};

void dfs(Node* node, const int depth) {
  if (!node) {
    return;
  }

  for (int i = 0; i < depth; i++) {
    cout << " ";
  }
  if (!node->_name.empty()) {
    cout << node->_name << endl;
  }

  sort(node->_children.begin(),
       node->_children.end(),
       cmp());

  for (int i = 0; i < (int) node->_children.size(); i++) {
    dfs(node->_children[i], depth + 1);
  }
}

vector<string> split(const string& s, const char delim) {
  stringstream ss(s);
  vector<string> tokens;
  string token;

  while (getline(ss, token, delim)) {
    if (token.size() > 0) {
      tokens.push_back(token);
    }
  }
  return tokens;
}


int main() {
  int N;
  cin >> N;

  Node* root_node = new Node("");

  for (int i = 0; i < N; i++) {
    string filename;
    cin >> filename;

    Node* current = root_node;
    vector<string> parts = split(filename, '\\');

    for (int i = 0; i < (int) parts.size(); i++) {
      current = current->get_or_create_child(parts[i]);
    }
  }

  // Filesystem tree preorder DFS
  dfs(root_node, -1);
}
