// Runtime: 4 ms, faster than 68.29% of C++ online submissions for Reverse Integer.
// Memory Usage: 8 MB, less than 100.00% of C++ online submissions for Reverse Integer.

class Solution {
 public:
  int reverse(int x) {
    int result = 0;
    while (x != 0) {
      if (result > INT_MAX / 10 || result < INT_MIN / 10) {
        return 0;
      }
      result *= 10;
      result += x % 10;
      x /= 10;
    }
    return result;
  }
};
