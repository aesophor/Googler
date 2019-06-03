// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Length of Last Word.
// Memory Usage: 8.9 MB, less than 44.90% of C++ online submissions for Length of Last Word.

class Solution {
 public:
  int lengthOfLastWord(string s) {
    if (s.empty()) {
      return 0;
    }
    
    int lastNonWhitespace = -1;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] != ' ') {
        lastNonWhitespace = i;
        break;
      }
    }
    
    for (int i = lastNonWhitespace - 1; i >= 0; i--) {
      if (s[i] == ' ') {
        return lastNonWhitespace - i;
      }
    }
    
    return lastNonWhitespace + 1;
  }
};<Paste>
