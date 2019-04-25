#include <iostream>
#include <string>

using namespace std;

bool isInputValid(const string& s) {
  for (auto c : s) {
    if ((c < '0' || c > '9') && c != '.') {
      return false;
    }
  }
  return true;
}

bool isWithinRange(int num, int lo, int hi) {
  return num >= lo && num <= hi;
}


int main() {
  string input;
  int num = 0;

  do {
    cout << "Please enter a number between 0 and 100: ";
    cin >> input;
  } while (!isInputValid(input) || !isWithinRange(stoi(input), 0, 100));

  num = stoi(input);
  cout << "Your input is: " << num << endl;
}
