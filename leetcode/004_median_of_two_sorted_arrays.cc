// Runtime: 40 ms, faster than 97.39% of C++ online submissions for Median of Two Sorted Arrays.
// Memory Usage: 21.4 MB, less than 69.44% of C++ online submissions for Median of Two Sorted Arrays.

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // if the merged array has odd number of elements, then median is at total_size / 2
        // if it has even number of elements, then median is at total_size / 2 and (total_size / 2) + 1
        int total_size = nums1.size() + nums2.size();
        bool even = total_size % 2 == 0;
        pair<int, int> median = { (even) ? (total_size / 2) - 1 : -1, total_size / 2 }; // -1 means not exist
        
        int num1_ptr = 0;
        int num2_ptr = 0;
        int current = 0;
        int total = 0;
        double result = 0.0;
        bool got_first = false;
        
        while (num1_ptr < nums1.size() || num2_ptr < nums2.size()) {        
            if (num1_ptr < nums1.size() && num2_ptr < nums2.size()) {
                if (nums1.at(num1_ptr) < nums2.at(num2_ptr)) {
                    current = nums1.at(num1_ptr);
                    num1_ptr++;
                } else {
                    current = nums2.at(num2_ptr);
                    num2_ptr++;
                }
            } else if (num1_ptr == nums1.size() && num2_ptr < nums2.size()) {
                current = nums2.at(num2_ptr);
                num2_ptr++;
            } else if (num1_ptr < nums1.size() && num2_ptr == nums2.size()) {
                current = nums1.at(num1_ptr);
                num1_ptr++;
            }
            
            if (!even && total == median.second) {
                result = current;
            } else if (even && total == median.first) {
                result = current;
            } else if (even && total == median.second) {
                result = (result + current) / 2;
                break;
            }
            
            total++; // count the number of elements we have iterated through
        }
        
        return result;
    }
};
