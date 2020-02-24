// Runtime: 52 ms, faster than 49.97% of C++ online submissions for Reverse String.
// Memory Usage: 15.3 MB, less than 70.73% of C++ online submissions for Reverse String.

class Solution {
 public:
  void reverseString(vector<char>& s) {
    int left = 0;
    int right = s.size() - 1;
    
    while (left < right) {
      // swap two chars
      std::swap(s[left], s[right]);
      left++;
      right--;
    }
  }
};
