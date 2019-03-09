// Runtime: 12 ms, faster than 95.04% of C++ online submissions for Two Sum.
// Memory Usage: 10.4 MB, less than 23.34% of C++ online submissions for Two Sum.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> complement_indices;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            if (complement_indices.find(complement) != complement_indices.end()) {
                // If the complement of nums[i] can be found, return it and i.
                return { complement_indices.at(complement), i };
            } else {
                // Record num's complement in the hash map.
                complement_indices[nums[i]] = i;    
            }
        }
        
        return { 0, 0 }; // The question didn't specify what to return if not found
    }
};
