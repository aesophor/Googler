#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    int p = 0;
    int nr_instructions;
    cin >> nr_instructions;

    bool instructions[100] = {};
    string line;

    for (int j = 0; j < nr_instructions; j++) {
      cin >> line;

      if (line == "LEFT") {
        --p;
        instructions[j] = 0;
      } else if (line == "RIGHT") {
        ++p;
        instructions[j] = 1;
      } else {
        cin >> line >> line;
        int n = atoi(line.c_str()) - 1;

        if (instructions[n] == 0) {
          --p;
        } else {
          ++p;
        }

        instructions[j] = instructions[n];
      }
    }

    cout << p << endl;
  }
}
