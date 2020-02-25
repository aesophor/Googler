// Runtime: 4 ms, faster than 70.07% of C++ online submissions for Length of Last Word.
// Memory Usage: 8.8 MB, less than 77.78% of C++ online submissions for Length of Last Word.

class Solution {
 public:
  int lengthOfLastWord(string s) {
    int last_char_pos = s.size() - 1;
    int result = 0;
    
    while (last_char_pos >= 0) {
      if (s[last_char_pos] != ' ') {
        break;
      }
      last_char_pos--;
    }
    
    while (last_char_pos >= 0) {
      if (s[last_char_pos] == ' ') {
        break;
      }
      last_char_pos--;
      result++;
    }
    
    return result;
  }
};
