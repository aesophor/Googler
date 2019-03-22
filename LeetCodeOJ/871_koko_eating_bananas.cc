// Runtime: 68 ms, faster than 60.61% of C++ online submissions for Koko Eating Bananas.
// Memory Usage: 10.9 MB, less than 62.71% of C++ online submissions for Koko Eating Bananas.

class Solution {
public:
  int minEatingSpeed(vector<int>& piles, int H) {
    // 吃香蕉的速度介於 1 ~ *std::max_element(piles.begin(), piles.end())
    int left = 1;
    int right = *std::max_element(piles.begin(), piles.end());
    
    while (left <= right) {
      int mid = left + (right - left) / 2;
      
      // Calculate the time needed to eat all bananas
      // under the speed at `mid`
      int time = 0;
      for (auto pile : piles) {
        time += std::ceil((double) pile / mid);
      }
      
      if (time < H) { // eats too fast, there's still time left
        right = mid - 1;
      } else if (time > H) { // eats too slow, using too much time
        left = mid + 1;
      } else { // time matches
        return mid;
      }
    }
    
    return left;
  }
};
