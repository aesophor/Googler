// Runtime: 16 ms, faster than 97.64% of C++ online submissions for String to Integer (atoi).
// Memory Usage: 14.6 MB, less than 32.19% of C++ online submissions for String to Integer (atoi).

class Solution {
public:
    int myAtoi(string str) {
        bool first_char_found = false;
        bool negative = false;
        int result = 0;
        
        for (auto c : str) {
            // Check if the first non-whitespace char is
            // '-' or digit
            if (!first_char_found) {
                if (c == ' ') {
                    continue;
                } else if (c == '-') {
                    first_char_found = true;
                    negative = true;
                } else if (c == '+') {
                    first_char_found = true;
                } else if (c >= '0' && c <= '9') {
                    first_char_found = true;
                    if (negative) {
                        result -= c - '0';
                    } else {
                        result += c - '0';
                    }
                } else {
                    return 0;
                }
            } else {
                if (c >= '0' && c <= '9') {
                    // Check if it will be out of range of int32
                    if (result > INT_MAX / 10) {
                        return INT_MAX;
                    } else if (result < INT_MIN / 10) {
                        return INT_MIN;
                    }
                    
                    // Reverse it brother
                    result *= 10;
                    int next_digit = c - '0';
                    
                    if (negative) {
                        if (result < INT_MIN + next_digit) {
                            return INT_MIN;
                        }
                        result -= next_digit;
                    } else {
                        if (result > INT_MAX - next_digit) {
                            return INT_MAX;
                        }
                        result += next_digit;
                    }
                } else {
                    return result;
                }
            }
        }
        
        return result;
    }
};
