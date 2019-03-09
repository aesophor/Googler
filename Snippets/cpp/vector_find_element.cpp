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
    for (int i = 0; i < 5; i++) {
        vec.push_back(i);
    }

    // check if vector has element
    if (find(vec.begin(), vec.end(), 3) != vec.end()) {
        cout << "found" << endl;
    }

    // find index of an element in a vector
    ptrdiff_t pos = find(vec.begin(), vec.end(), 3) - vec.begin();
    if (pos < (int) vec.size()) {
        cout << "item index is: " << pos << endl;
    }


    // Erase
    show_vector(vec);
    cout << "Size before erase: " << vec.size() << endl;
    vec.erase(vec.begin() + 2, vec.begin() + 3); // erase item at index 2
    cout << "Size after erase: " << vec.size() << endl;
    //vec.erase(vec.begin() + 2, vec.begin() + 4); // erase item at index 2, 3
    //vec.erase(vec.begin(), vec.begin() + vec.size()); // erase item at index 2, 3, 4
    show_vector(vec);

    // Erase Remove idiom
    vec.erase( remove(vec.begin(), vec.end(), 5) , vec.end());
    show_vector(vec);

    // Insert shit at a specific index
    //vec.insert(vec.begin() + 5, 8);
    //show_vector(vec);
}
