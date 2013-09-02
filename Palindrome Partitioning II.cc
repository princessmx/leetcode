// Small: 4ms; Large: 328ms
class Solution {
 public:
  int minCut(string s) {
    vector<int> min_cut(s.size() + 1);
    vector<vector<bool> > palindrome(s.size(), vector<bool>(s.size(), false));
    for (int i = s.size() - 1; i >= 0; i--) {
      palindrome[i][i] = true;
    }
    min_cut[s.size()] = -1;
    min_cut[s.size() - 1] = 0;
    for (int i = s.size() - 2; i >= 0; i--) {
      min_cut[i] = 1 + min_cut[i + 1];
      for (int j = i + 1; j < s.size(); j++) {
        palindrome[i][j] =
          (s[i] == s[j]) && (j == i + 1 || palindrome[i + 1][j - 1]);
        if (palindrome[i][j]) {
          min_cut[i] = min(min_cut[i], 1 + min_cut[j + 1]);
        }
      }
    }
    return min_cut[0];
  }
};
