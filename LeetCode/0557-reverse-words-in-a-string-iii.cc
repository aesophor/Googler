// Runtime: 24 ms, faster than 63.08% of C++ online submissions for Reverse Words in a String III.
// Memory Usage: 11.9 MB, less than 47.83% of C++ online submissions for Reverse Words in a String III.

class Solution {
 public:
  string reverseWords(string s) {
    int left = 0;
    int right = 0;
    
    while (right < s.size()) {
      if (s[right] == ' ') {
        reverseSubstring(s, left, right - 1);
        left = right + 1;
      } else if (right == s.size() - 1) {
        reverseSubstring(s, left, right);
      }
      right++; 
    }
    
    return s;
  }
  
 private:
  void reverseSubstring(string& s, int left, int right) {
    while (left < right) {
      std::swap(s[left], s[right]);
      left++;
      right--;
    }
  }
};
