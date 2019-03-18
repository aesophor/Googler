// Runtime: 12 ms, faster than 97.87% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
// Memory Usage: 10.7 MB, less than 90.52% of C++ online submissions for Find First and Last Position of Element in Sorted Array.

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // Always prepare for outliers
        if (nums.size() == 0) {
            return {-1, -1};
        }
        
        // [5,7,7,8,8,10]
        //          ^
        // in this example, using binary search we will find 8 at this position
        // we should then look for adjacent elements that are also 8.
        int index = binarySearch(nums, 0, nums.size() - 1, target);
        
        if (index == -1) {
            return {-1, -1};
        }
        
        // Look for the leftmost element index.
        int left = index;
        while (left > 0 && nums.at(left - 1) == target) {
            left--;
        }
        
        // Look for the rightmost element index.
        int right = index;
        while (right < nums.size() - 1 && nums.at(right + 1) == target) {
            right++;
        }
        
        return {left, right};
    }
    
    int binarySearch(vector<int>& nums, int left, int right, int target) {
        if (right < 0) {
            return -1;
        } else if (left == right) {
            return (nums.at(left) == target) ? left : -1;
        }
        
        int mid = (left + right) / 2;
        
        if (nums.at(mid) < target) {
            return binarySearch(nums, mid + 1, right, target);
        } else if (nums.at(mid) == target) {
            return mid;
        } else {
            return binarySearch(nums, left, mid - 1, target);
        }
    }
};
