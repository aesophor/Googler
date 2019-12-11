#include <iostream>
#include <string>

using namespace std;

int main() {
  int count = 0;
  cin >> count;

  for (int i = 0; i < count; i++) {
    int min_in = 0;
    int min_out = 0;
    cin >> min_in >> min_out;

    float fee = 0;

    if (min_in <= 300) {
      fee = min_in * 3 + min_out * 6 * 1;
    } else if (min_in <= 500) {
      fee = min_in * 3 * 0.9 + min_out * 6 * 1;
    } else if (min_in <= 1000) {
      fee = min_in * 3 * 0.75 + min_out * 6 * 0.9;
    } else {  // min_total >= 1001
      fee = min_in * 3 * 0.5 + min_out * 6 * 0.75;
    }

    cout << ((int) fee) << endl;
  }
}
