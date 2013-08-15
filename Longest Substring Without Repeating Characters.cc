// Small: 4ms; Large: 76ms
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int last[256];
    memset(&last, -1, sizeof(last));
    int start = 0, end = 0;
    int length = 0, max_length = 0;
    while (end < s.size()) {
      if (last[s[end]] < 0) {
        last[s[end]] = end;
      } else {
        length = end - start;
        if (max_length < length) {
          max_length = length;
        }
        while (start <= last[s[end]]) {
          last[s[start]] = -1;
          start++;
        }
        last[s[end]] = end;
      }
      end++;
    }
    length = end - start;
    if (max_length < length) {
      max_length = length;
    }
    return max_length;
  }
};
