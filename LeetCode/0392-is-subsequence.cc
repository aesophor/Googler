// Runtime: 56 ms, faster than 96.54% of C++ online submissions for Is Subsequence.
// Memory Usage: 17.2 MB, less than 33.33% of C++ online submissions for Is Subsequence.

class Solution {
 public:
  bool isSubsequence(string s, string t) {
    int p = 0;
    
    for (auto c : t) {
      if (c == s[p]) {
        p++;
        if (p == s.size()) {
          return true;
        }
      }
    }
    
    return p == s.size();
  }
};
