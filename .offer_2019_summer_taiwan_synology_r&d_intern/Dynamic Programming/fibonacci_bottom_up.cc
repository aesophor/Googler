#include <iostream>

using namespace std;

int fibonacci(int n) {
  // fib      | 0 1 1 2 3 5 8 13 21 34 55 89 144
  // -------------------------------------------
  // dp array | 0 1 2 3 4 5 6  7  8  9 10 11  12

  int dp[n+1];
  dp[1] = dp[2] = 1;

  for (int i = 3; i <= n; i++) {
    dp[i] = dp[i-1] + dp[i-2];
  }
  return dp[n];
}

int main() {
  cout << fibonacci(10) << endl;
}
