// Runtime: 100 ms, faster than 99.24% of C++ online submissions for Squares of a Sorted Array.
// Memory Usage: 14.2 MB, less than 81.50% of C++ online submissions for Squares of a Sorted Array.

class Solution {
public:
  vector<int> sortedSquares(vector<int>& A) {
    // Find the element that is closest to 0 using binary search. O(log(n))
    int left = 0;
    int right = A.size() - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (A.at(mid) < 0) {
        left = mid + 1;
      } else if (A.at(mid) > 0) {
        right = mid - 1;
      } else { // equals
        left = mid;
        break;
      }
    }
    
    // Calibrate binary search result XDDDD
    if (left + 1 < A.size() && std::abs(A.at(left + 1)) < std::abs(A.at(left))) {
      left++;
    }
    if (left - 1 >= 0 && std::abs(A.at(left - 1)) < std::abs(A.at(left))) {
      left--;
    }
    
    // 'Left' should be the index of element that is closest to zero.
    // This part is similar to merge sort. O(n)
    // Total: O(n log(n))
    vector<int> squares(A.size());
    squares.at(0) = A.at(left) * A.at(left);
    
    int pleft = left - 1;
    int pright = left + 1;
    for (int i = 1; i < A.size(); i++) { // we've already handled 0
      if (pleft >= 0 && pright == A.size()) {
        squares.at(i) = A.at(pleft) * A.at(pleft);
        pleft--;
      } else if (pleft == -1 && pright < A.size()) {
        squares.at(i) = A.at(pright) * A.at(pright);
        pright++;
      } else { // both pleft and pright are within range
        if (std::abs(A.at(pleft)) <= std::abs(A.at(pright))) {
          squares.at(i) = A.at(pleft) * A.at(pleft);
          pleft--;
        } else {
          squares.at(i) = A.at(pright) * A.at(pright);
          pright++;
        }
      }
    }
      
    return squares;
  }
};

// -5 -3 -2 -4 -1
