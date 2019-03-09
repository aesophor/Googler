#include "binary_search_tree.hpp"
#include <iostream>

int main() {
    BinarySearchTree bst = BinarySearchTree();
    bst.Add(5);
    bst.Add(18);
    bst.Add(2);
    bst.Add(1);
    bst.Add(3);
    
    std::cout << bst << std::endl;
}
