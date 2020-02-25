// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Detect Capital.
// Memory Usage: 8.4 MB, less than 12.50% of C++ online submissions for Detect Capital.

class Solution {
 public:
  bool detectCapitalUse(string word) {
    if (!isUpper(word[0])) {
      // All remaining letters should be lowercase.
      for (int i = 1; i < word.size(); i++) {
        if (isUpper(word[i])) {
          return false;
        }
      }
      
    } else if (word.size() == 1) {
      return true;
    } else if (isUpper(word[1])) {
      // All remaining letters should be uppercase.
      for (int i = 2; i < word.size(); i++) {
        if (isLower(word[i])) {
          return false;
        }
      }
    } else {  // isLower(word[1])
      // All remaining letters should be lowercase.
      for (int i = 2; i < word.size(); i++) {
        if (isUpper(word[i])) {
          return false;
        }
      }
    }
    return true;
  }
  
 private:
  inline bool isUpper(const char c) {
    return c >= 'A' && c <= 'Z';
  }
  
  inline bool isLower(const char c) {
    return c >= 'a' && c <= 'z';
  }
};
