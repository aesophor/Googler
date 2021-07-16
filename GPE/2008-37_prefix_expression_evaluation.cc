#include <bits/stdc++.h>

using namespace std;

void solve(const vector<string>& tokens) {
  stack<int> s;

  for (int i = tokens.size() - 1; i >= 0; i--) {
    const string& token = tokens[i];
    int result = 0;

    if (token == "+" ||
        token == "-" ||
        token == "*" ||
        token == "/" ||
        token == "%") {
      if (s.empty()) {
        // illegal 的情況，記得直接 return
        // 而不是 break 了再去檢查 s.size() 是否爲 1
        cout << "illegal" << endl;
        return;
      }
      int operand1 = s.top();
      s.pop();

      if (s.empty()) {
        cout << "illegal" << endl;
        return;
      }
      int operand2 = s.top();
      s.pop();

      if (token == "+") {
        result = operand1 + operand2;
      } else if (token == "-") {
        result = operand1 - operand2;
      } else if (token == "*") {
        result = operand1 * operand2;
      } else if (token == "/") {
        result = operand1 / operand2;
      } else if (token == "%") {
        result = operand1 % operand2;
      }
    } else {
      result = atoi(token.c_str());
    }

    s.push(result);
  }

  if (s.size() == 1) {
    cout << s.top() << endl;
  } else {
    cout << "illegal" << endl;
  }
}

int main() {
  string line;

  while (getline(cin, line) && line != ".") {
    stringstream sin(line);
    vector<string> tokens;
    string token;

    while (sin >> token) {
      tokens.push_back(token);
    }

    solve(tokens);
  }
}
