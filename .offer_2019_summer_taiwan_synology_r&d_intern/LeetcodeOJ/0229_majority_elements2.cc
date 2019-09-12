// Runtime: 12 ms, faster than 97.33% of C++ online submissions for Majority Element II.
// Memory Usage: 10.8 MB, less than 9.93% of C++ online submissions for Majority Element II.

class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (auto num : nums) {
      freq[num]++;
    }
    
    vector<int> maxElements;
    int maxFreq = INT_MIN;
    for (auto& f : freq) {
      if (f.second > (int) nums.size() / 3) {
        maxFreq = f.second;
        maxElements.push_back(f.first);
      }
    }
    return maxElements;
  }
};
