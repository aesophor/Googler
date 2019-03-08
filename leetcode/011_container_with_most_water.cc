// Runtime: 20 ms, faster than 98.67% of C++ online submissions for Container With Most Water.
// Memory Usage: 10 MB, less than 71.49% of C++ online submissions for Container With Most Water.

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        
        int begin = 0;
        int end = height.size() - 1;
        
        while (begin != end) {
            int area = (end - begin) * min(height.at(begin), height.at(end));
            max_area = max(max_area, area);
            
            if (height.at(begin) < height.at(end)) {
                begin++;
            } else {
                end--;
            }
        }
        
        return max_area;
    }
};
