// Runtime: 32 ms, faster than 98.56% of C++ online submissions for Sort Array By Parity.
// Memory Usage: 11.1 MB, less than 91.32% of C++ online submissions for Sort Array By Parity.

class Solution {
public:
  vector<int> sortArrayByParity(vector<int>& A) {
    int left = 0;
    int right = A.size() - 1;
    
    while (left < right) {
      int& l = A.at(left);
      int& r = A.at(right);
      if (!isEven(l) && isEven(r)) {
        std::swap(l, r);
        left++;
        right--;
      } else if (isEven(l) && isEven(r)) {
        left++; // 左邊繼續往右找，想辦法把右邊even換到左邊
      } else if (!isEven(l) && !isEven(r)) {
        right--; // 右邊繼續往左找，想辦法把左邊odd換到右邊
      } else { // isEven(l) && !isEven(r)
        left++;
        right--;
      }
    }
    
    return A;
  }
  
  inline bool isEven(const int& num) {
    return num % 2 == 0;
  }
};

// [3,1,2,4]
// [4,2,1,3]

// [3,1,2,2,1,2,2,4]
// [4,1,2,2,1,2,2,3]
// [4,2,2,2,1,2,1,3]
// [4,2,2,2,2,1,1,3]
