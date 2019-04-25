// Runtime: 24 ms, faster than 94.84% of C++ online submissions for Count Primes.
// Memory Usage: 9.8 MB, less than 31.79% of C++ online submissions for Count Primes.

class Solution {
public:
  int countPrimes(int n) {
    if (n < 2) {
      return 0;
    }

    // less than a non-negative number, n
    bool is_prime[n]; // 0 1 2 ... n - 1
    for (int i = 0; i < n; i++) {
      is_prime[i] = true;
    }
    is_prime[0] = false;
    is_prime[1] = false;
    int total = n - 2;

    for (int i = 2; i <= std::sqrt(n); i++) {
      if (is_prime[i]) {
        for (int j = 2; i * j < n; j++) {
          int multiple = i * j;
          if (is_prime[multiple]) {
            is_prime[multiple] = false;
            total--;
          }
        }
      }
    }
    return total;
  }
};
