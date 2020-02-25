// Runtime: 4 ms, faster than 96.30% of C++ online submissions for Longest Common Prefix.
// Memory Usage: 8.8 MB, less than 79.03% of C++ online submissions for Longest Common Prefix.

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
      return "";
    }
    
    for (int i = 0; i < strs.front().size(); i++) {
      for (int j = 1; j < strs.size(); j++) {
        if (i >= strs[j].size() || strs[j][i] != strs.front()[i]) {
          return strs.front().substr(0, i);
        }
      }
    }
    
    return strs.front();
  }
};
