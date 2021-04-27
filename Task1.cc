// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S, vector<int> &C) {
    int ret = 0;
    size_t left = 0;
    size_t right = 0;

    while (left < S.size()) {
        // Keep searching from i until a different letter is reached.
        // For all duplicate letters found, we will drop the one with
        // the maximum removal cost.
        right = left;
        int max_cost = 0;
        int max_cost_idx = left;

        for (; right < S.size() && S[right] == S[left]; right++) {
            if (C[right] > max_cost) {
                max_cost = C[right];
                max_cost_idx = right;
            }
        }

        // No adjacent duplicate letters found.
        if (left == right) {
            ++left;
            continue;
        }

        // Add the costs of removal to `ret`, except for the largest one.
        for (size_t i = left; i < right; i++) {
            ret += (i != max_cost_idx) ? C[i] : 0;
        }

        left = right;
    }

    return ret;
}
