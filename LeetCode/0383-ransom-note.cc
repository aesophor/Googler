// Runtime: 32 ms, faster than 42.87% of C++ online submissions for Ransom Note.
// Memory Usage: 11.1 MB, less than 75.00% of C++ online submissions for Ransom Note.

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    std::unordered_map<char, int> charCount;
    
    for (const auto c : magazine) {
      charCount[c]++;
    }
    
    
    for (const auto c : ransomNote) {
      auto it = charCount.find(c);
      if (it == charCount.end()) {
        return false;
      }
      if (--(it->second) == 0) {
        charCount.erase(c);
      }
    }
    
    return true;
  }
};
