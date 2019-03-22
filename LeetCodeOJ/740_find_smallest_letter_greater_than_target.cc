// Runtime: 16 ms, faster than 95.76% of C++ online submissions for Find Smallest Letter Greater Than Target.
// Memory Usage: 10 MB, less than 69.12% of C++ online submissions for Find Smallest Letter Greater Than Target.

class Solution {
public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    int left = 0;
    int right = letters.size() - 1;
    
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (letters.at(mid) <= target) {
        left = mid + 1;
      } else if (letters.at(mid) > target) {
        right = mid - 1;
      }
    }
    
    if (left == letters.size()) {
      left = 0;
    }
    return letters.at(left);
  }
};
