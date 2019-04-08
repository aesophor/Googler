#include <iostream>
#include <unordered_map>

using namespace std;

int fib(int n, unordered_map<int, int>& cache) {
    if (cache.find(n) != cache.end()) {
        cout << "using DP cache: " << n << endl;
        return cache.at(n);
    }

    int result = 1;
    if (n == 1 || n == 2) {
        result = 1;
    } else {
        result = fib(n - 1, cache) + fib(n - 2, cache);
        cache[n] = result;
    }
    return result;
}

int main() {
    unordered_map<int, int> cache;
    cout << "8th items in fib array: " << fib(8, cache) << endl;
}
