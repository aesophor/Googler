#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void show_vector(const vector<int>& vec) {
    for (auto i : vec) {
        cout << i << " ";
    }
    cout << endl;
}


int main() {
    vector<int> vec;
    for (int i = 0; i < 15; i++) {
        vec.push_back(i);
    }

    // check if vector has element
    if (find(vec.begin(), vec.end(), 5) != vec.end()) {
        cout << "found" << endl;
    }

    // find index of an element in a vector
    ptrdiff_t pos = find(vec.begin(), vec.end(), 5) - vec.begin();
    if (pos < (int) vec.size()) {
        cout << "item index is: " << pos << endl;
    }


    // Remove shit from vector
    vec.erase( remove(vec.begin(), vec.end(), 5) , vec.end());
    show_vector(vec);

    // Insert shit at a specific index
    vec.insert(vec.begin() + 5, 8);
    show_vector(vec);
}
