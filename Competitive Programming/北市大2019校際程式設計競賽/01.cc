#include <iostream>
#include <random>
#include <vector>

using namespace std;

int IntRand(int lo, int hi) {
  return rand() % (hi - lo + 1) + lo;
}

int main() {
  srand(time(nullptr));

  // Generate n random numbers in [20,100].
  vector<int> freq(100 - 20 + 1, 0);
  int mode = 0;
  int max_freq = 0;

  for (int i = 0; i < IntRand(0, 100); i++) {
    int num = IntRand(20, 100);
    freq[num - 20]++;

    if (freq[num - 20] > max_freq) {
      max_freq = freq[num - 20];
      mode = num;
    }
  }

  for (int i = 0; i < (int) freq.size(); i++) {
    cout << i + 20 << ": " << freq[i] << endl;
  }
  cout << "Mode: " << mode << " (" << max_freq << ")" << endl;
}
