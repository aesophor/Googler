#include <iostream>
#include <string>

using namespace std;

string upperCaseIt(string s) {
  // 用 reference 把 s 裏面的每個char轉大寫
  for (auto& c : s) {
    c = toupper(c);
  }
  // 這時 s 裏面每個char已是大寫
  // 用 return-by-value 復制一整個新的string回去
  return s;
}

bool sameString(string s1, string s2) {
  return upperCaseIt(s1) == upperCaseIt(s2);
}


int main() {
  string s1, s2;
  cout << "Please enter two names: ";
  cin >> s1 >> s2;

  cout << sameString(s1, s2);
  return 0;
}
