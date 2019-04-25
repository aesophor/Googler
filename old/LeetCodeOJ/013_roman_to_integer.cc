// Runtime: 44 ms, faster than 97.79% of C++ online submissions for Roman to Integer.
// Memory Usage: 31 MB, less than 68.32% of C++ online submissions for Roman to Integer.

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        
        for (int i = 0; i < s.size(); i++) {
            // Check for special cases
            if (i + 1 < s.size() && s.at(i) == 'I' && s.at(i + 1) == 'V') {
                result += 4;
                i++;
            } else if (i + 1 < s.size() && s.at(i) == 'I' && s.at(i + 1) == 'X') {
                result += 9;
                i++;
            } else if (i + 1 < s.size() && s.at(i) == 'X' && s.at(i + 1) == 'L') {
                result += 40;
                i++;
            } else if (i + 1 < s.size() && s.at(i) == 'X' && s.at(i + 1) == 'C') {
                result += 90;
                i++;
            } else if (i + 1 < s.size() && s.at(i) == 'C' && s.at(i + 1) == 'D') {
                result += 400;
                i++;
            } else if (i + 1 < s.size() && s.at(i) == 'C' && s.at(i + 1) == 'M') {
                result += 900;
                i++;
            } else {
                switch (s.at(i)) {
                    case 'I':
                        result += 1;
                        break;
                    case 'V':
                        result += 5;
                        break;
                    case 'X':
                        result += 10;
                        break;
                    case 'L':
                        result += 50;
                        break;
                    case 'C':
                        result += 100;
                        break;
                    case 'D':
                        result += 500;
                        break;
                    case 'M':
                        result += 1000;
                        break;
                    default:
                        break;
                }
            }
        }
        
        return result;
    }
};
