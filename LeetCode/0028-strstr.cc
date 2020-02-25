// Runtime: 4 ms, faster than 91.15% of C++ online submissions for Implement strStr().
// Memory Usage: 9.2 MB, less than 35.71% of C++ online submissions for Implement strStr().

class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle.empty()) {
      return 0;
    }
    
    if (haystack.size() < needle.size()) {
      return -1;
    }
    
    
    for (int i = 0; i < haystack.size(); i++) {
      if (i + needle.size() > haystack.size()) {
        break;
      }
      
      if (haystack[i] == needle[0]) {
        for (int j = 0; j < needle.size(); j++) {
          if (haystack[i + j] != needle[j]) {
            break;
          } else if (j == needle.size() - 1 && haystack[i + j] == needle[j]) {
            return i;
          }
        }
      }
    }
    
    return -1;
  }
};
