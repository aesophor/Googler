// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Length of Last Word.
// Memory Usage: 9 MB, less than 66.33% of C++ online submissions for Length of Last Word.

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) {
            return 0;
        }
        
        bool detected_word = false;
        int last_word_size = 0;
        
        for (int i = s.size() - 1; i >= 0; i--) {
            if (!detected_word && s.at(i) != ' ') {
                // The first character has been spotted
                detected_word = true;
            } else if (detected_word && s.at(i) == ' ') {
                return last_word_size;
            }
            
            if (detected_word) {
                last_word_size++;
            }
        }
        
        return last_word_size;
    }
};

// Hello World
//           ^
//          10
