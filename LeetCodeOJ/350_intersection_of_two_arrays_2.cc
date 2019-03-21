// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Intersection of Two Arrays II.
// Memory Usage: 8.8 MB, less than 99.36% of C++ online submissions for Intersection of Two Arrays II.

class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    // We will search each element in small in big.
    vector<int>& big = (nums1.size() > nums2.size()) ? nums1 : nums2;
    vector<int>& small = (nums1.size() > nums2.size()) ? nums2 : nums1;
    std::sort(big.begin(), big.end());
    std::sort(small.begin(), small.end());

    vector<int> found;
    for (int i = 0; i < small.size(); i++) {
      // Perform binary search on the big vector.
      int left = 0;
      int right = big.size() - 1;
      
      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (big.at(mid) < small.at(i)) {
          left = mid + 1;
        } else if (big.at(mid) > small.at(i)) {
          right = mid - 1;
        } else { // equals
          found.push_back(small.at(i));
          big.erase(find(big.begin(), big.end(), small.at(i)));
          break;
        }
      }
    }
    
    return found;
  }
};
