// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Jewels and Stones.
// Memory Usage: 9.7 MB, less than 87.46% of C++ online submissions for Jewels and Stones.

class Solution {
public:
  int numJewelsInStones(string J, string S) {
    int jewel_count = 0;
    for (auto stone : S) {
      if (J.find(stone) != std::string::npos) {
        jewel_count++;
      }
    }
    return jewel_count;
  }
};
