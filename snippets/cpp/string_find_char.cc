#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s = "hello";
    std::sort(s.begin(), s.end());
    cout << s << endl;
    cout << (s.find('l')) << endl;

    vector<string> vec;

    string a;
    a += 'c';
    vec.push_back(a);
}
