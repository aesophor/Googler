#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<int> set = { 1, 1, 2 };

    for (auto& element : set) {
        cout << element << endl;
    }
}
