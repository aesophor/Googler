#include <iostream>
#include <memory>

class Tree {
 public:
  struct Node {
    Node(int data) : data(data) {}
    virtual ~Node() {
      std::cout << "Node::~Node();" << std::endl;
    }

    int data;
  };

  Tree() : root_(new Node(3)) {
    std::cout << "ref count: " << root_.use_count() << std::endl;
  }
  virtual ~Tree() {
    std::cout << "Tree::~Tree();" << std::endl;
  }

  std::shared_ptr<Tree::Node> getRoot() {
    return root_;
  }

 private:
  std::shared_ptr<Tree::Node> root_;
};


int main() {
  std::unique_ptr<Tree> tree(new Tree());

  {
    std::shared_ptr<Tree::Node> sp1 = tree->getRoot();
    std::cout << "ref count: " << sp1.use_count() << std::endl;

    {
      std::shared_ptr<Tree::Node> sp2 = tree->getRoot();
      std::cout << "ref count: " << sp2.use_count() << std::endl;
    }

    std::cout << "ref count: " << sp1.use_count() << std::endl;
  }
}
