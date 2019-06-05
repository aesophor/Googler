#include <iostream>
#include <string>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool isPrime(int n) {
  if (n >= 0 && n < 2) {
    return true;
  }

  // Sieve of Eratosthenes's algorithm to find primes
  // def: If we know that 2 is a prime, then 4, 6, 8, 10, 12 ... are not primes
  // we can use a for loop to detect all multiples of 2 within the given range
  
  // We assume that all numbers within [0,n] are primes at first
  // Then we'll strike out all multiples of a prime.
  
  // [0, 1, 2, 3, 4, 5, ..., n]
  bool prime[n + 1];
  for (int i = 0; i <= n; i++) {
    prime[i] = true;
  }
  prime[0] = false;
  prime[1] = false;
  
  for (int i = 2; i <= std::sqrt(n); i++) {
    if (prime[i]) {
      for (int j = 2; i * j <= n; j++) {
        prime[i * j] = false;
      }
    }
  }

  return prime[n];
}


int main() {
  string s;
  while (std::getline(cin, s)) {
    cout << (isPrime(std::stoi(s)) ? "YES" : "NO") << endl;
  }
}
