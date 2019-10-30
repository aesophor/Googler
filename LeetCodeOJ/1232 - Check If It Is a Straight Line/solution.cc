// Runtime: 8 ms, faster than 94.73% of C++ online submissions for Check If It Is a Straight Line.
// Memory Usage: 10.2 MB, less than 100.00% of C++ online submissions for Check If It Is a Straight Line.

class Solution {
 public:
  bool checkStraightLine(vector<vector<int>>& coordinates) {
    int sampleSlope = getSlope(coordinates.front(), coordinates.back());
    
    for (int i = 0; i < coordinates.size() - 1; i++) {
      if (sampleSlope != getSlope(coordinates[i], coordinates[i + 1])) {
        return false;
      }
    }
    return true;
  }
  
 private:
  double getSlope(vector<int>& p1, vector<int>& p2) {
    return ((double) p2[1] - p1[1]) / (p2[0] - p1[0]);
  }
};
