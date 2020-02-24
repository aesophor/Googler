// Runtime: 52 ms, faster than 38.46% of C online submissions for Reverse String.
// Memory Usage: 13.4 MB, less than 100.00% of C online submissions for Reverse String.

void reverseString(char* s, int sSize){
  int left = 0;
  int right = sSize - 1;
  
  while (left < right) {
    // swap two chars
    int tmp = s[left];
    s[left] = s[right];
    s[right] = tmp;
    
    left++;
    right--;
  }
}
