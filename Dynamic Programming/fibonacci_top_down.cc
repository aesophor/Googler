#include <iostream>
#include <unordered_map>

using namespace std;

// Gets the i-th item in the fibonacci sequence.
int fibonacci(unordered_map<int, int>& memo, int i) {
  if (memo.find(i) != memo.end()) {
    return memo[i];
  }

  int result = 0;
  if (i <= 2) {
    result = 1;
  } else {
    result = fibonacci(memo, i - 2) + fibonacci(memo, i - 1);
  }
  memo[i] = result;
  return result;
}

int main() {
  unordered_map<int, int> memo;
  cout << fibonacci(memo, 10) << endl;
}
