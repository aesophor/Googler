#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Pstring : public string {
 public:
  Pstring(string s) : string(s) {}
  bool isPalindrome();
};

int main() {
  string input;
  cin >> input;
  Pstring s(input);
}
