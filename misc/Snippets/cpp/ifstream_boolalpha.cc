#include <iostream>
#include <fstream>

using namespace std;

int main() {
  bool b = false;

  ifstream fin("config.txt"); // contains a string "true"
  fin >> boolalpha >> b;

  cout << b << endl;
}
