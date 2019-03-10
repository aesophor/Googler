// Runtime: 8 ms, faster than 99.50% of C++ online submissions for Trapping Rain Water.
// Memory Usage: 10.8 MB, less than 76.06% of C++ online submissions for Trapping Rain Water.

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        
        // DP; Two pass; time: O(n); space: O(n)
        int left_highest[height.size()];
        
        int left_max = 0;
        for (int i = 0; i < height.size(); i++) {
            left_highest[i] = left_max;
            left_max = std::max(left_max, height.at(i));
        }
        
        int area = 0;
        int right_max = 0;
        for (int i = height.size() - 1; i >= 0; i--) {
            // Calculate water area minus the height of the ground
            int current = height.at(i);
            if (current < left_highest[i] && current < right_max) {
                area += std::min(left_highest[i], right_max) - current;
            }
            
            right_max = std::max(right_max, height.at(i));
        }
        
        return area;
    }
};


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
