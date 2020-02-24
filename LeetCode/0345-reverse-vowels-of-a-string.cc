// Runtime: 4 ms, faster than 99.81% of C++ online submissions for Reverse Vowels of a String.
// Memory Usage: 10.1 MB, less than 69.70% of C++ online submissions for Reverse Vowels of a String.

class Solution {
 public:
  string reverseVowels(string s) {
    int left = 0;
    int right = s.size() - 1;
    
    while (left < right) {
      bool leftVowel = isVowel(s[left]);
      bool rightVowel = isVowel(s[right]);
      
      if (leftVowel && rightVowel) {
        std::swap(s[left], s[right]);
        left++;
        right--;
      } else if (leftVowel && !rightVowel) {
        right--;
      } else if (!leftVowel && rightVowel) {
        left++;
      } else {
        left++;
        right--;
      }
    }
    
    return s;
  }
  
 private:
  inline bool isVowel(const char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
      || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
  }
};
