// Runtime: 88 ms, faster than 50.93% of C++ online submissions for Sort Array By Parity II.
// Memory Usage: 12.8 MB, less than 17.37% of C++ online submissions for Sort Array By Parity II.

class Solution {
 public:
  vector<int> sortArrayByParityII(vector<int>& A) {
    vector<int> wrongOdd; // index
    vector<int> wrongEven; // index
    
    for (int i = 0; i < A.size(); i++) {
      if (isEven(i) != isEven(A[i])) {
        if (isEven(i)) {
          wrongEven.push_back(i);
        } else {
          wrongOdd.push_back(i);
        }
      }
    }
    
    for (auto pos : wrongOdd) {
      int target = wrongEven.back();
      wrongEven.pop_back();
      std::swap(A[pos], A[target]);
    }
    
    return A;
  }
  
 private:
  bool isEven(int num) {
    return num % 2 == 0;
  }
};
