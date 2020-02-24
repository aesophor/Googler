// Runtime: 4 ms, faster than 69.49% of C++ online submissions for Reverse Integer.
// Memory Usage: 8.2 MB, less than 89.52% of C++ online submissions for Reverse Integer.

class Solution {
 public:
  int reverse(int x) {
    int result = 0;
    
    while (x != 0) {
      if ((x > 0 && result > INT_MAX / 10) || (x < 0 && result < INT_MIN / 10)) {
        return 0;
      }
      result *= 10;
      
      int digit = x % 10;
      if ((x > 0 && result > INT_MAX - digit) || (x < 0 && result < INT_MIN - digit)) {
        return 0;
      }
      result += x % 10;
      
      x /= 10;
    }
    
    return result;
  }
};
