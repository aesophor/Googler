// Runtime: 4 ms, faster than 59.31% of C++ online submissions for Binary Tree Preorder Traversal.
// Memory Usage: 9.2 MB, less than 93.10% of C++ online submissions for Binary Tree Preorder Traversal.

class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    quickSort(nums, 0, nums.size() - 1);
    return nums;
  }
  
 private:
  void quickSort(vector<int>& nums, int lo, int hi) {
    if (lo < hi) {
      int pivot = partition(nums, lo, hi);
      
      quickSort(nums, lo, pivot - 1);
      quickSort(nums, pivot + 1, hi);
    }
  }
  
  int partition(vector<int>& nums, int lo, int hi) {
    int pivot = nums[hi];
    int i = 0;
    
    for (int j = lo; j < hi; j++) {
      if (nums[j] <= pivot) {
        i++;
        std::swap(nums[i], nums[j]);
      }
    }
    
    std::swap(nums[++i], nums[hi]);
    return i;
  }
};
