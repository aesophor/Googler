// Runtime: 36 ms, faster than 97.89% of C++ online submissions for Product of Array Except Self.
// Memory Usage: 12.6 MB, less than 51.51% of C++ online submissions for Product of Array Except Self.

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int left_prods[nums.size()];
    left_prods[0] = 1;
    
    for (int i = 1; i < nums.size(); i++) {
      left_prods[i] = left_prods[i - 1] * nums[i - 1];
    }
    
    std::vector<int> result(nums.size());
    int right_prod = 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
      result[i] = left_prods[i] * right_prod;
      right_prod *= nums[i];
    }
    
    return result;
  }
};
