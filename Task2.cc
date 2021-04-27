// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <numeric>

string solution(int U, int L, vector<int> &C) {
    string upper;
    string lower;

    // U + L should equal to the summation of C.
    if (U + L != std::accumulate(C.begin(), C.end(), 0)) {
        return "IMPOSSIBLE";
    }

    // Build row0
    for (size_t i = 0; i < C.size(); i++) {
        if (U > 0 && C[i] > 0) {
            upper += "1";
            U--;
            C[i]--;
        } else {
            upper += "0";
        }
    }

    // Build row1
    for (size_t i = 0; i < C.size(); i++) {
        if (L > 0 && C[i] > 0) {
            lower += "1";
            L--;
            C[i]--;
        } else {
            lower += "0";
        }
    }

    return upper + "," + lower;
}
