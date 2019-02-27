#ifndef BINARY_SEARCH_TREE_HPP_
#define BINARY_SEARCH_TREE_HPP_

#include <iostream>

class BinarySearchTree {
private:
    struct Node {
        Node(int v) : parent(), left_child(), right_child(), value(v) {}
        Node* parent;
        Node* left_child;
        Node* right_child;
        int value;
    };

    Node* root_;

public:
    BinarySearchTree();
    virtual ~BinarySearchTree() = default;

    void Add(int value);
    void Remove(int value);

    void PreOrderTraversal(std::ostream& os, Node* node) const;
    void InOrderTraversal(std::ostream& os, Node* node) const;
    void PostOrderTraversal(std::ostream& os, Node* node) const;

    friend std::ostream& operator<< (std::ostream& os, const BinarySearchTree& bst);
};

#endif
