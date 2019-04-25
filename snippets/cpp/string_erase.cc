#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s = "aello";
    cout << s.find('l') << endl;
    s.erase(std::find(s.begin(), s.end(), 'l'));
    cout << s << endl;
}
