// Runtime: 40 ms, faster than 93.08% of C++ online submissions for Product of Array Except Self.
// Memory Usage: 12.8 MB, less than 32.68% of C++ online submissions for Product of Array Except Self.

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> leftProducts(nums.size(), 1);
    for (int i = 1; i < nums.size(); i++) {
      leftProducts[i] = leftProducts[i - 1] * nums[i - 1];
    }
    
    vector<int> result(nums.size(), 1);
    int rightProduct = 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
      result[i] = leftProducts[i] * rightProduct;
      rightProduct *= nums[i];
    }
    return result;
  }
};
