// Runtime: 68 ms, faster than 70.52% of C++ online submissions for Longest Palindromic Substring.
// Memory Usage: 6.7 MB, less than 80.80% of C++ online submissions for Longest Palindromic Substring.

class Solution {
 public:
  string longestPalindrome(string s) {
    if (s.size() < 2) {
      return s;
    }
    
    // Final Result
    int pos = 0;
    int len = 0;
    
    // Result of each loop iteration is stored here.
    // Declared outside of the loops for performance sake.
    pair<int, int> result;
    
    
    for (size_t i = 0; i < s.size(); i++) {
      result = findOddPalindromicSubstring(s, i);
      if (result.second > len) {
        pos = result.first;
        len = result.second;
      } 
    }
    
    for (size_t i = 0; i < s.size() - 1; i++) { 
      result = findEvenPalindromicSubstring(s, i);
      if (result.second > len) {
        pos = result.first;
        len = result.second;
      }
    }
    
    return s.substr(pos, len);
  }
  
 private:
  // Attempt to expand from `centerIndex` and obtain
  // the longest palindromic substring.
  pair<int,int>
  findOddPalindromicSubstring(const string& s, int centerIndex) {
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
    return {left, right - left + 1};
  }
  
  
  // Attempt to expand from `centerIndex` and `centerIndex + 1` and obtain
  // the longest palindromic substring.
  pair<int, int>
  findEvenPalindromicSubstring(const string& s, int centerIndex) {
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
    return {left, right - left + 1};
  }
};
