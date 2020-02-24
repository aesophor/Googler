// Runtime: 12 ms, faster than 73.60% of C++ online submissions for Palindrome Number.
// Memory Usage: 8.1 MB, less than 87.27% of C++ online submissions for Palindrome Number.

class Solution {
 public:
  bool isPalindrome(int x) {
    return x >= 0 && x == reverseInt(x);
  }
  
 private:
  long reverseInt(int x) {
    long result = 0;
    
    while (x != 0) {
      result *= 10;
      result += x % 10;
      x /= 10;
    }
    
    return result;
  }
};
