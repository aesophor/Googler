// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Rotate String.
// Memory Usage: 8.4 MB, less than 81.03% of C++ online submissions for Rotate String.

class Solution {
public:
  bool rotateString(string A, string B) {
    return A.length() == B.length() && (A + A).find(B) != std::string::npos;
  }
};
