// Runtime: 176 ms, faster than 53.05% of C++ online submissions for N-ary Tree Postorder Traversal.
// Memory Usage: 33.5 MB, less than 24.80% of C++ online submissions for N-ary Tree Postorder Traversal.

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
    vector<int> postorder(Node* root) {
        if (!root) {
            return result_;
        }
        
        // Traverse the children from left -> right
        for (auto child : root->children) {
            postorder(child);
        }
        result_.push_back(root->val);
        return result_;
    }
    
private:
    vector<int> result_;
};


// Iterative
/*
Definition for a Node.
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
    vector<int> postorder(Node* root) {
        if (!root) {
            return result_;
        }

        stack<Node*> st;
        Node* node = root;
        st.push(root);
        while (!st.empty()) {
            for (auto child : node->children) {
                st.push(child);
            }

            result_.insert(result_.begin(), node->val);
            node = st.top();
            st.pop();
        }

        return result_;
    }

private:
    inline bool isLeaf(Node* node) {
        return node->children.empty();
    }

    vector<int> result_;
};
