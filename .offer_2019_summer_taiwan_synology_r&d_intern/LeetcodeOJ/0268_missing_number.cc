// Runtime: 24 ms, faster than 92.22% of C++ online submissions for Missing Number.
// Memory Usage: 9.9 MB, less than 18.15% of C++ online submissions for Missing Number.

class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int upperBound = getUpperBound(nums);
    int expectedSum = (1 + upperBound) * nums.size() / 2;
    int actualSum = std::accumulate(nums.begin(), nums.end(), 0);
    return (upperBound == nums.size()) ? expectedSum - actualSum : upperBound + 1;
  }
  
 private:
  int getUpperBound(const vector<int>& nums) {
    int max = INT_MIN;
    for (auto num : nums) {
      max = std::max(max, num);
    }
    return max;
  }
};

// [0, 1]  range=0,1,2  upper=1  size=2
// [0, 2]  range=0,1,2  upper=2  size=2

// [3, 0, 1] range=0,1,2,3 upper=3 size=3
