// Runtime: 16 ms, faster than 72.90% of C++ online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 11.1 MB, less than 43.28% of C++ online submissions for Longest Substring Without Repeating Characters.

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int left = 0;
    int right = 0;
    int max_len = 0;
    std::unordered_map<char, int> appeared_idx;
    
    while (right < s.size()) {
      auto it = appeared_idx.find(s[right]);
      
      // Has not appeared before
      if (it == appeared_idx.end()) {
        appeared_idx.insert({s[right], right});
      // Has appeared before, but not in current window
      } else if (it->second < left) {
        it->second = right;
      // Has appeared before and it's in current window
      } else {
        max_len = std::max(max_len, right - left);
        left = it->second + 1;
        it->second = right;
      }
      
      right++;
    }
    
    return std::max(max_len, right - left);
  }
};
