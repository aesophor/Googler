// Runtime: 24 ms, faster than 92.60% of C++ online submissions for Count Primes.
// Memory Usage: 10 MB, less than 30.79% of C++ online submissions for Count Primes.

class Solution {
 public:
  int countPrimes(int n) {
    if (n < 2) {
      return 0;
    }
    
    // [0, 1, 2, 3, 4, 5, ..., n-1]
    bool isPrime[n];
    std::fill_n(isPrime, n, true);
    isPrime[0] = false;
    isPrime[1] = false;
    
    int count = n - 2;
    for (int i = 2; i <= std::sqrt(n); i++) {
      if (isPrime[i]) {
        for (int j = 2; i * j < n; j++) {
          if (isPrime[i * j]) {
            isPrime[i * j] = false;
            count--;
          }
        }
      }
    }
    return count;
  }
};
