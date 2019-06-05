#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

namespace {

vector<string> split(const string& s, const char delimiter=' ') {
  std::stringstream ss(s);
  string t;
  vector<string> tokens;

  while (std::getline(ss, t, delimiter)) {
    if (t.length() > 0) {
      tokens.push_back(t);
    }
  }
  return tokens;
}

string toLower(const string& s) {
  string result;
  for (auto c : s) {
    if (c >= 'A' && c <= 'Z') {
      result += c + ('a' - 'A');
    } else {
      result += c;
    }
  }
  return result;
}

string toUpper(const string& s) {
  string result;
  for (auto c : s) {
    if (c >= 'a' && c <= 'z') {
      result += c - ('a' - 'A');
    }
  }
  return result;
}

} // namespace

int main() {
  string line1;
  while (std::getline(cin, line1)) {
    string line2;
    string line3;
    string line4;
    std::getline(cin, line2);
    std::getline(cin, line3);
    std::getline(cin, line4);

    string& vocab = line1;
    int n = std::stoi(line2);
    bool left = line3 == "L";

    vector<string> tokens = ::split(line4);
    vector<string> result;

    for (int i = 0; i < (int) tokens.size(); i++) {
      if (toLower(tokens[i]) == vocab) {
        string s;
        for (int j = i - 1; j >= i - n && j >= 0; j--) {
          if (j != n - 1 && j != 0) {
            s = " " + s;
          }
          s = toLower(tokens[j]) + s;
          if (j == 0 || j == i - n) {
            //s += " ";
          }
        }
        s += toUpper(vocab) + " ";
        for (int j = i + 1; j <= i + n && j < (int) tokens.size(); j++) {
          s += toLower(tokens[j]);
          if (j != (int) tokens.size()) {
            s += " ";
          }
        }
        s += '\n';
        result.push_back(s);
      }
    }

    // sort this bad bitch
    
    for (auto s : result) {
      cout << s;
    }
  }
}
