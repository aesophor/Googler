// Runtime: 80 ms, faster than 5.80% of C++ online submissions for Sqrt(x).
// Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Sqrt(x).

class Solution {
 public:
  int mySqrt(int x) {
    if (x == 0) {
      return 0;
    }
    
    int result = 0;
    int product = 0;

    for (int i = 1; i < INT_MAX / i && (product = i * i) <= x; i++) {
      result = i;
    }
    
    return result;
  }
};
