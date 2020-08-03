// Runtime: 84 ms, faster than 62.82% of C++ online submissions for Longest Palindromic Substring.
// Memory Usage: 22.3 MB, less than 38.03% of C++ online submissions for Longest Palindromic Substring.

class Solution {
 public:
  string longestPalindrome(string s) {
    if (s.size() < 2) {
      return s;
    }
    
    // Result
    //int pos = 0;
    //int len = 0;
    
    string ret;
    string result;
    
    for (size_t i = 0; i < s.size(); i++) {
      result = findOddPalindromicSubstring(s, i);
      if (result.size() > ret.size()) {
        ret = result;
      }
    }
    
    for (size_t i = 0; i < s.size() - 1; i++) { 
      result = findEvenPalindromicSubstring(s, i);
      if (result.size() > ret.size()) {
        ret = result;
      }
    }
    
    return ret;
  }
  
 private:
  // Attempt to expand from `centerIndex` and obtain
  // the longest palindromic substring.
  string findOddPalindromicSubstring(const string& s, int centerIndex) {
    int left = centerIndex;
    int right = centerIndex;
    
    while (left >= 0 && right < s.size()) {
      if (s.at(left) != s.at(right)) {
        break;
      }
      left--;
      right++;
    }
    
    left++;
    right--;
    return s.substr(left, right - left + 1);
  }
  
  
  // Attempt to expand from `centerIndex` and `centerIndex + 1` and obtain
  // the longest palindromic substring.
  string findEvenPalindromicSubstring(const string& s, int centerIndex) {
    int left = centerIndex;
    int right = centerIndex + 1;
    
    while (left >= 0 && right < s.size()) {
      if (s.at(left) != s.at(right)) {
        break;
      }
      left--;
      right++;
    }
    
    left++;
    right--;
    return s.substr(left, right - left + 1);
  }
};
