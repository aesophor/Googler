#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> vv1;
    vv1.push_back({1,2,3});

    vector<vector<int>> vv2;
    vv2.push_back({1,2,3});

    cout << (vv1 == vv2) << endl;
}
