// Runtime: 68 ms, faster than 63.96% of C++ online submissions for Total Hamming Distance.
// Memory Usage: 10.3 MB, less than 80.00% of C++ online submissions for Total Hamming Distance.

// 解法：对于每个bit，把0的个数 * 1的个数就是该bit的hamming distance。

class Solution {
 public:
  int totalHammingDistance(vector<int>& nums) {
    int dist = 0;
    
    for (int i = 0; i < 32; i++) {
      int num_zero = 0;
      int num_one = 0;
      
      for (auto& n : nums) {
        if (n % 2 == 1) {
          num_one++;
        } else {
          num_zero++;
        }
        n >>= 1;
      }
      
      dist += num_zero * num_one;
    }
    
    return dist;
  }
};
