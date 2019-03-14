// Runtime: 60 ms, faster than 81.18% of C++ online submissions for Sliding Window Maximum.
// Memory Usage: 13.1 MB, less than 62.37% of C++ online submissions for Sliding Window Maximum.

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> q;
        
        for (int i = 0; i < nums.size(); i++) {
            // deque內容超出視窗範圍，pop_front
            if (!q.empty() && q.front() == i - k) {
                q.pop_front();
            }
            
            // nums.at(i) 比 deque 內最大數字還大
            if (!q.empty() && nums.at(i) > nums.at(q.front())) {
                q.clear();
            }
            
            // 目前window最大的還是最左邊的element，但我們
            // 要把 deque 中間小於 nums.at(i) 的廢物清掉
            while (!q.empty() && nums.at(q.back()) < nums.at(i)) {
                q.pop_back();
            }
            
            q.push_back(i);
            
            if (i >= k - 1) {
                result.push_back(nums.at(q.front()));
            }
        }
        return result;
    }
};

// [1,3,1,2,0,5]

// 1
// 3
// 31 

// 312
//  ^
// 這裏應該要清掉1,因爲2比1大，1之後不可能是max了，所以用一個while迴圈清掉他

// 120
