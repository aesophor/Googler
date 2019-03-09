// Runtime: 36 ms, faster than 83.61% of C++ online submissions for Count Primes.
// Memory Usage: 9.7 MB, less than 33.77% of C++ online submissions for Count Primes.

class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) {
            return 0;
        }
        
        // Sieve of Eratosthenes's algorithm to find primes
        // def: If we know that 2 is a prime, then 4, 6, 8, 10, 12 ... are not primes
        // we can use a for loop to detect all multiples of 2 within the given range
        
        // We assume that all numbers within [0,n-1] are primes at first
        // Then we'll strike out all multiples of a prime.
        // int total = n; // 0 ~ n - 1
        // total -= 2; // We know that 0 and 1 are NOT primes
        bool is_prime[n];
        for (int i = 0; i < n; i++) {
            is_prime[i] = true;
        }
        is_prime[0] = false;
        is_prime[1] = false;
        int total = n - 2;
        
        for (int i = 2; i <= std::sqrt(n); i++) {
            if (is_prime[i]) {
                for (int j = 2; i * j < n; j++) {
                    if (is_prime[i * j]) {
                        is_prime[i * j] = false;
                        total--;
                    }
                }
            }
        }
        
        return total;
    }
};
