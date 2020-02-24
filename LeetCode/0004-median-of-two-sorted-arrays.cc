// Runtime: 20 ms, faster than 72.51% of C++ online submissions for Median of Two Sorted Arrays.
// Memory Usage: 9.6 MB, less than 86.60% of C++ online submissions for Median of Two Sorted Arrays.

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    size_t total = nums1.size() + nums2.size();
    bool even = total % 2 == 0;

    int p1 = 0;
    int p2 = 0;
    int steps = 0;

    int prev_num = 0;
    int current_num = 0;
    

    while (p1 < nums1.size() || p2 < nums2.size()) {
      
      if (p1 < nums1.size() && p2 < nums2.size()) {
        if (nums1[p1] <= nums2[p2]) {
          current_num = nums1[p1++];
        } else {
          current_num = nums2[p2++];
        }

      } else if (p1 < nums1.size() && p2 >= nums2.size()) {
        current_num = nums1[p1++];

      } else if (p1 >= nums1.size() && p2 < nums2.size()) {
        current_num = nums2[p2++];
      }

      if (steps == total / 2) {
        return (even) ? ((double) prev_num + current_num) / 2 : current_num;
      }
      
      prev_num = current_num;
      steps++;
    }
    
    return -1;
  }
};
