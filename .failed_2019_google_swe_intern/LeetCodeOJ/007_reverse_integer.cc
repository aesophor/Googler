// Runtime: 12 ms, faster than 98.46% of C++ online submissions for Reverse Integer.
// Memory Usage: 14 MB, less than 59.72% of C++ online submissions for Reverse Integer.

class Solution {
public:
  int reverse(int x) {
    int reversed = 0;

    while (x != 0) {
      if (reversed > INT_MAX / 10 || reversed < INT_MIN / 10) {
        return 0;
      }
      reversed *= 10;
      reversed += (x % 10);
      x /= 10;
    }

    return reversed;
  }
};

// 123

// 12 3

// 1 32

// 0 321
