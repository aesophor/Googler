// Runtime: 8 ms, faster than 91.41% of C++ online submissions for Merge Sorted Array.
// Memory Usage: 9 MB, less than 73.33% of C++ online submissions for Merge Sorted Array.

class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // Copy the initialized elements from nums1 to another vector.
    vector<int> nums1_copy(m);
    for (int i = 0; i < m; i++) {
      nums1_copy.at(i) = nums1.at(i);
    }
    
    // Perform merge sort (merge part, O(m+n))
    int pnum1 = 0;
    int pnum2 = 0;
    int i = 0;
    while (pnum1 < m || pnum2 < n) {
      if (pnum1 == m && pnum2 < n) {
        nums1.at(i) = nums2.at(pnum2);
        pnum2++;
      } else if (pnum1 < m && pnum2 == n) {
        nums1.at(i) = nums1_copy.at(pnum1);
        pnum1++;
      } else { // pnum1 < m && pnum2 < n
        if (nums1_copy.at(pnum1) <= nums2.at(pnum2)) {
          nums1.at(i) = nums1_copy.at(pnum1);
          pnum1++;
        } else { // >
          nums1.at(i) = nums2.at(pnum2);
          pnum2++;
        }
      }
      i++;
    }
  }
};
