#include <iostream>
#include <climits>

int main() {
  int N = 0;
  int minPos = INT_MAX;
  int maxPos = 0;

  std::cin >> N;
  for (int i = 0; i < N + 1; i++) {
    int pos = 0;
    std::cin >> pos;
    minPos = std::min(minPos, pos);
    maxPos = std::max(maxPos, pos);
  }

  std::cout << (maxPos - minPos) * 2 << std::endl;
}
