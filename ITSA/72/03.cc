#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int main() {
  string line1;
  while (std::getline(cin, line1)) {
    string line2;
    string line3;
    std::getline(cin, line2);
    std::getline(cin, line3);

    string& delim = line2;
    int rowCount = std::stoi(line3);
    vector<string> data;
    for (int i = 1; i <= rowCount; i++) {
      data.push_back({});
    }
    int i = 0;
    for (char c : line1) {
      if (data[i].empty()) {
        data[i] = c;
      } else {
        data[i] = string(1, c) + delim + data[i];
      }
      i++;
      i = i % rowCount;
    }

    for (auto s : data) {
      cout << s << endl;
    }
  }
}
