// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Intersection of Two Arrays.
// Memory Usage: 9.1 MB, less than 76.86% of C++ online submissions for Intersection of Two Arrays.

class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    // We will search each element in small in big.
    vector<int>& big = (nums1.size() > nums2.size()) ? nums1 : nums2;
    vector<int>& small = (nums1.size() > nums2.size()) ? nums2 : nums1;
    std::sort(big.begin(), big.end());
    std::sort(small.begin(), small.end());
    
    unordered_set<int> found;
    
    for (auto num : small) {
      // Perform binary search in big.
      int left = 0;
      int right = big.size() - 1;
      
      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (big.at(mid) < num) {
          left = mid + 1;
        } else if (big.at(mid) > num) {
          right = mid - 1;
        } else { // equals
          found.insert(num);
          break;
        }
      }
    }
    
    // Convert unordered_set to vector and return it.
    vector<int> result;
    for (auto num : found) {
      result.push_back(num);
    }
    return result;
  }
};
