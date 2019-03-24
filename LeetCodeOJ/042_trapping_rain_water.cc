// Runtime: 8 ms, faster than 99.50% of C++ online submissions for Trapping Rain Water.
// Memory Usage: 10.8 MB, less than 76.06% of C++ online submissions for Trapping Rain Water.

class Solution {
public:
  int trap(vector<int>& height) {
    if (height.empty()) {
      return 0;
    }
    
    int area = 0;
    
    vector<int> left_highest(height.size());
    left_highest.at(0);
    
    for (int i = 1; i < height.size(); i++) {
      left_highest.at(i) = std::max(left_highest.at(i - 1), height.at(i - 1));
    }
    
    int right_highest = 0;
    for (int i = height.size() - 1; i >= 0; i--) {
      int& current_height = height.at(i);
      if (current_height < left_highest.at(i) && current_height < right_highest) {
        area += std::min(left_highest.at(i), right_highest) - current_height;
      }
      right_highest = std::max(right_highest, current_height);
    }
    
    return area;
  }
};

// [0,1,0,2,1,0,1,3,2,1,2,1]
// [0,0,1,1,2,2,2,3,3,3,3,3] l
// []

/*
bruteforce:

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        
        int max_height = *std::max_element(height.begin(), height.end());
        int area = 0;
        
        for (int y = 0; y < max_height; y++) {
            for (int x = 1; x < height.size() - 1; x++) { // Ignore the border of the map
                // Check if this (x,y) is inside a wall
                if (y < height.at(x)) {
                    continue;
                }
            
                // Leftward raycasting
                bool has_left_wall = false;
                for (int i = x - 1; i >= 0; i--) {
                    if (height.at(i) > y) {
                        has_left_wall = true;
                        break;
                    }
                }
                    
                // Rightward raycasting
                bool has_right_wall = false;
                for (int i = x + 1; i < height.size(); i++) {
                    if (height.at(i) > y) {
                        has_right_wall = true;
                        break;
                    }
                }
                    
                if (has_left_wall && has_right_wall) {
                    area++;
                }
            }
        }
        
        return area;
    }
};
*/
