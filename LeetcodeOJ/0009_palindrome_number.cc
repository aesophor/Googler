// Runtime: 32 ms, faster than 72.82% of C++ online submissions for Palindrome Number.
// Memory Usage: 8.2 MB, less than 63.96% of C++ online submissions for Palindrome Number.

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    
    int original = x;
    int reversed = 0;
    int len = 0;
    while (x != 0) {
      if (reversed > INT_MAX / 10 || reversed < INT_MIN / 10) {
        return false; // ???
      }
      reversed *= 10;
      reversed += x % 10;
      x /= 10;
      len++;
    }
    
    for (int i = 0; i < std::ceil(len / 2.0); i++) {
      int originalLastDigit = original % 10;
      int reversedLastDigit = reversed % 10;
      cout << originalLastDigit << "vs" << reversedLastDigit << endl;
      
      if (originalLastDigit != reversedLastDigit) {
        return false;
      }
      
      original /= 10;
      reversed /= 10;
    }
    return true;
  }
};
