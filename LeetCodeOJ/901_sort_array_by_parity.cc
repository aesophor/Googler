// Runtime: 32 ms, faster than 98.56% of C++ online submissions for Sort Array By Parity.
// Memory Usage: 11.1 MB, less than 91.32% of C++ online submissions for Sort Array By Parity.

class Solution {
public:
  vector<int> sortArrayByParity(vector<int>& A) {
    int left = 0;
    int right = A.size() - 1;
    
    while (left < right) {
      bool left_is_even = isEven(A.at(left));
      bool right_is_even = isEven(A.at(right));
      
      if (!left_is_even && right_is_even) {
        std::swap(A.at(left), A.at(right));
        left++;
        right--;
      } else if (left_is_even && right_is_even) {
        left++; // 左邊繼續往右找，想辦法把右邊even換到左邊
      } else if (!left_is_even && !right_is_even) {
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
