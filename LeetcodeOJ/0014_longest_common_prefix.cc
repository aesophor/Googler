// Runtime: 8 ms, faster than 86.27% of C++ online submissions for Longest Common Prefix.
// Memory Usage: 15.2 MB, less than 5.03% of C++ online submissions for Longest Common Prefix.

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
      return "";
    }
    
    string commonPrefix;
    int minStrLength = getMinStrLength(strs);
    
    for (int i = 0; i < minStrLength; i++) {
      bool isSameChar = true;
      char firstChar = strs[0][i];
      for (auto s : strs) {
        if (s[i] != firstChar) {
          return commonPrefix;
        }
      }
      commonPrefix += firstChar;
    }
    return commonPrefix;
  }
    
 private:
  int getMinStrLength(const vector<string>& strs) {
    int minStrLength = strs[0].size();
    for (int i = 1; i < strs.size(); i++) {
      minStrLength = std::min(minStrLength, (int) strs[i].size());
    }
    return minStrLength;
  }
};
