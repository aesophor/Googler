// Runtime: 12 ms, faster than 82.16% of C++ online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 10.7 MB, less than 66.17% of C++ online submissions for Longest Substring Without Repeating Characters.

class Solution {
 public:
  int lengthOfLongestSubstring(const string& s) {
    std::unordered_map<char, int> m; // <char, last_appeared_idx>
    int left = 0;
    int result = 0;
    
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      auto it = m.find(c);

      if (it != m.end()) {
        left = std::max(left, it->second + 1);
      }
      
      result = std::max(result, i - left + 1);
      m[c] = i; // update last appeared position
    }
    
    return result;
  }
};

// dvdf
// 0123

// left = 1
// result = 0
// <d,2> <v,1>
// 
