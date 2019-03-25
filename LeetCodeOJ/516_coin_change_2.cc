// Runtime: 8 ms, faster than 99.33% of C++ online submissions for Coin Change 2.
// Memory Usage: 8.8 MB, less than 70.59% of C++ online submissions for Coin Change 2.

class Solution {
public:
  int change(int amount, vector<int>& coins) {
    vector<int> memo(1 + amount, 0);
    memo.at(0) = 1;
    
    for (auto coin : coins) {
      for (int i = 1; i <= amount; i++) {
        if (i >= coin) {
          memo.at(i) += memo.at(i - coin);
        }
      }
    }
    
    return memo.back();
  }
};
