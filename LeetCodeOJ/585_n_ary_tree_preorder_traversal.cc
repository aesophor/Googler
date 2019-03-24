// Runtime: 156 ms, faster than 99.20% of C++ online submissions for N-ary Tree Preorder Traversal.
// Memory Usage: 33.3 MB, less than 47.22% of C++ online submissions for N-ary Tree Preorder Traversal.

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        if (!root) {
            return result_;
        }
        
        result_.push_back(root->val);
        for (auto child : root->children) {
            preorder(child);
        }
        return result_;
    }

private:
    vector<int> result_;
};


// Iterative
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
  vector<int> preorder(Node* root) {
    if (!root) {
      return {};
    }

    vector<int> result;
    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
      Node* top = st.top();
      result.push_back(top->val);
      st.pop();

      for (int i = top->children.size() - 1; i >= 0; i--) {
        st.push(top->children.at(i));
      }
    }

    return result;
  }
};
