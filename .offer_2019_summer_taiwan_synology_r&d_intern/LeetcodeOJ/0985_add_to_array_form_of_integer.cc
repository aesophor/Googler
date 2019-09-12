// Runtime: 112 ms, faster than 94.84% of C++ online submissions for Add to Array-Form of Integer.
// Memory Usage: 12.5 MB, less than 83.07% of C++ online submissions for Add to Array-Form of Integer.

class Solution {
 public:
  vector<int> addToArrayForm(vector<int>& A, int K) {
    int pos = A.size() - 1;
    while (K != 0) {
      if (pos < 0) {
        A.insert(A.begin(), 0);
        pos++;
      }
      A[pos] += K % 10;
      K /= 10;
      for (int i = pos; i >= 0; i--) {
        if (A[i] >= 10) {
          A[i] -= 10;
          if (i - 1 < 0) {
            A.insert(A.begin(), 1);
            pos++;
          } else {
            A[i - 1] += 1;
          }
        }
      }
      pos--;
    }
    return A;
  }
};
