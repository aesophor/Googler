// Runtime: 4 ms, faster than 88.43% of C++ online submissions for First Bad Version.
// Memory Usage: 8.3 MB, less than 5.41% of C++ online submissions for First Bad Version.

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
 public:
  int firstBadVersion(int n) {
    int lo = 1;
    int hi = n;
    
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (isBadVersion(mid)) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    
    return lo;
  }
};

// o o o x x | x x x x x
