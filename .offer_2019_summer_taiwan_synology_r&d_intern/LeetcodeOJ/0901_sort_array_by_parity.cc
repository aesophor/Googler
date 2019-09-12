// Runtime: 28 ms, faster than 90.76% of C++ online submissions for Sort Array By Parity.
// Memory Usage: 9.7 MB, less than 71.17% of C++ online submissions for Sort Array By Parity.

class Solution {
 public:
  vector<int> sortArrayByParity(vector<int>& A) {
    int lo = 0;
    int hi = A.size() - 1;
    
    while (lo < hi) {
      bool isLeftEven = isEven(A[lo]);
      bool isRightEven = isEven(A[hi]);
      
      while (lo < hi && isEven(A[lo])) {
        lo++;
      }
      while (lo < hi && !isEven(A[hi])) {
        hi--;
      }
      std::swap(A[lo], A[hi]);
    }
    
    return A;
  }
  
 private:
  bool isEven(int num) {
    return num % 2 == 0;
  }
};
