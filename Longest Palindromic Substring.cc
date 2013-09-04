// Small: 40ms; Large: 836ms
class Solution {
 public:
  string longestPalindrome(string s) {
    memset(palindrome_, false, sizeof(palindrome_));
    for (int i = 0; i < s.size(); i++) {
      palindrome_[i][i] = true;
    }
    int max_length = 1, index = 0;
    for (int i = s.size() - 2; i >= 0; i--) {
      for (int j = i + 1; j < s.size(); j++) {
        if (s[i] == s[j] && (j == i + 1 || palindrome_[i + 1][j - 1])) {
          palindrome_[i][j] = true;
          if (max_length < j - i + 1) {
            max_length = j - i + 1;
            index = i;
          }
        }
      }
    }
    return s.substr(index, max_length);
  }
 private:
  bool palindrome_[1000][1000];
};
