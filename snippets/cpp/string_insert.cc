#include <iostream>
#include <string>

using namespace std;

int main() {
  std::string s = "hellorld";
  cout << s.insert(s.find("rld"), "wo") << endl;
}
