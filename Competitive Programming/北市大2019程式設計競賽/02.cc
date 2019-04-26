#include <iostream>
#include <random>
#include <vector>

using namespace std;

int RandInt(int lo, int hi) {
  return rand() % (hi - lo + 1) + lo;
}

int main() {
  srand(time(nullptr));

  vector<int> freq('z' - 'A' + 1, 0);
  int n = RandInt(10, 52);
  char mode = 'A';
  int max_freq = 0;

  for (int i = 0; i < n; i++) {
    char c[2];
    c[0] = RandInt('A', 'Z');
    c[1] = RandInt('a', 'z');
    char ch = c[RandInt(0, 1)];
    freq[ch - 'A']++;

    if (freq[ch - 'A'] > max_freq) {
      mode = ch;
      max_freq = freq[ch - 'A'];;
    }
  }

  for (int i = 0; i < (int) freq.size(); i++) {
    cout << (char) ('A' + i) << ": " << freq[i] << endl;
  }
  cout << "Mode: " << mode << " (" << max_freq << ")" << endl;
}
