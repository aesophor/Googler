#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;

  while (cin >> s) {
    string result;
    string r(s);
    reverse(r.begin(), r.end());

    for (size_t i = 0; i < r.size(); i++) {
      if (s.substr(i, r.size() - i) == r.substr(0, r.size() - i)) {
        result = s.substr(0, i) + r;
        break;
      }
    }

    cout << result << endl;
  }
}
