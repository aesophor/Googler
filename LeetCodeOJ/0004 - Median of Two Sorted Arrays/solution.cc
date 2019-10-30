// Runtime: 16 ms, faster than 90.73% of C++ online submissions for Median of Two Sorted Arrays.
// Memory Usage: 10.2 MB, less than 36.08% of C++ online submissions for Median of Two Sorted Arrays.

// Time space complexities are both in O(log(m+n))

class Solution {
 public:
  double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    int total = nums1.size() + nums2.size();
    int target = total / 2;
    bool is_total_odd = total % 2 != 0;
    
    std::vector<int> merged;
    int p1 = 0;
    int p2 = 0;
    
    while (merged.size() != total) {
      if (p1 == nums1.size()) { // nums1 search complete, search nums2
        merged.push_back(nums2[p2++]);
      } else if (p2 == nums2.size()) { // nums2 search complete, search nums1
        merged.push_back(nums1[p1++]);
      } else {
        merged.push_back((nums1[p1] >= nums2[p2]) ? nums2[p2++] : nums1[p1++]);
      }

      // total is odd: simply return the last shit in merged vector
      // total is even: calculate the average of the last two shit
      if (merged.size() == target + 1) {
        return (is_total_odd) ? merged.back() : ((double) merged[target] + merged[target - 1]) / 2;
      }
    }
    
    return 0;
  }
};
