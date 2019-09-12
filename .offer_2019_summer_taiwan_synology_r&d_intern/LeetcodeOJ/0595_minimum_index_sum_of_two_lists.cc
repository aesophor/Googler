// Runtime: 104 ms, faster than 88.99% of C++ online submissions for Minimum Index Sum of Two Lists.
// Memory Usage: 28.7 MB, less than 45.42% of C++ online submissions for Minimum Index Sum of Two Lists.

class Solution {
 public:
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    unordered_map<string, int> m;
    vector<string> result;
    int minSum = INT_MAX;
    
    for (int i = 0; i < list2.size(); i++) {
      m.insert({list2[i], i});
    }
    
    for (int i = 0; i < list1.size(); i++) {
      if (m.find(list1[i]) != m.end()) {
        if (m[list1[i]] + i < minSum) {
          minSum = m[list1[i]] + i;
          result.clear();
          result.push_back(list1[i]);
        } else if (m[list1[i]] + i == minSum) {
          result.push_back(list1[i]);
        }
      }
    }
    
    return result;
  }
};
