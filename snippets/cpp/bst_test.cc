#include <iostream>
#include <cassert>

template <typename Data>
class Tree {
 public:
  Tree() : root(), isize() {}
  virtual ~Tree() = default;
  virtual bool insert(const Data& item);

 private:
  struct BSTNode {
    BSTNode(const Data& data) : left(), right(), data(data) {}
    BSTNode* left;
    BSTNode* right;
    Data data;
  };

  BSTNode* root;
  int isize;
};


template <typename Data>
bool Tree<Data>::insert(const Data& data) {
  if (!root) { // when the tree is originally empty
    root = new BSTNode(data);

  } else {
    BSTNode* iterNode = root;

    while (iterNode) {
      if (iterNode->data > data) {
        if (iterNode->left) {
          iterNode = iterNode->left;
        } else {
          iterNode->left = new BSTNode(data);
          break;
        }

      } else if (iterNode->data < data) {
        if (iterNode->right) {
          iterNode = iterNode->right;
        } else {
          iterNode->right = new BSTNode(data);
          break;
        }

      } else { // iterNode->data == data ...@_@
        return false;
      }
    }
  }

  isize++;
  return true;
}


int main(int argc, char* args[]) {
  Tree<int> tree;
  assert(tree.insert(5));
  assert(tree.insert(4));
  assert(tree.insert(2));
  assert(tree.insert(3));
  // assert(tree.insert(3)); -> core dumped
}
