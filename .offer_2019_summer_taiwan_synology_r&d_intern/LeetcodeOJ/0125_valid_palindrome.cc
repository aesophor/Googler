// Runtime: 8 ms, faster than 94.84% of C++ online submissions for Valid Palindrome.
// Memory Usage: 9.5 MB, less than 17.60% of C++ online submissions for Valid Palindrome.

class Solution {
 public:
  bool isPalindrome(string s) {
    if (s.empty()) {
      return true;
    }
    
    int lo = 0;
    int hi = (int) s.size() - 1;
    
    while (lo < hi) {
      while (lo < s.size() && !isAlphaNumeric(s[lo])) {
        lo++;
      }
      while (hi >= 0 && !isAlphaNumeric(s[hi])) {
        hi--;
      }
      
      if (lo >= s.size() || hi < 0) {
        return true;
      }
      
      if (std::tolower(s[lo]) != std::tolower(s[hi])) {
        return false;
      }
      lo++;
      hi--;
    }
    return true;
  }
  
 private:
  bool isAlphaNumeric(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= ' z') || (c >= '0' && c <= '9');
  }
};
