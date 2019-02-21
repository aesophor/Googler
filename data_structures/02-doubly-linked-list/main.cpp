#include "linked_list.cpp"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    LinkedList<int> list;
    list.push_back(3);
    list.push_back(0);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);
    list.reverse();
    cout << list.ToString() << endl;
}
