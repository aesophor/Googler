// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Perfect Square.
// Memory Usage: 8.1 MB, less than 90.48% of C++ online submissions for Valid Perfect Square.

class Solution {
 public:
  bool isPerfectSquare(int num) {
    if (num < 0) {
      return false;
    }
    
    if (num == 0) {
      return true;
    }
    
    int product = 0;
    
    for (int i = 1; i <= INT_MAX / i && (product = i * i) <= num; i++) {
      if (product == num) {
        return true;
      }
    }

    return false;
  }
};
