// Small: 8ms; Large: 24ms
class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s3.size() != s1.size() + s2.size()) {
      return false;
    }
    vector<vector<bool> > interleave(
        s1.size() + 1, vector<bool>(s2.size() + 1, false));
    interleave[0][0] = true;
    for (int i = 1; i <= s1.size(); i++) {
      interleave[i][0] = s3[i - 1] == s1[i - 1];
    }
    for (int i = 1; i <= s2.size(); i++) {
      interleave[0][i] = s3[i - 1] == s2[i - 1];
    }
    for (int i = 1; i <= s1.size(); i++) {
      for (int j = 1; j <= s2.size(); j++) {
        int k = i + j - 1;
        if ((s1[i - 1] == s3[k] && interleave[i - 1][j]) ||
            (s2[j - 1] == s3[k] && interleave[i][j - 1])) {
          interleave[i][j] = true;
        }
      }
    }
    return interleave[s1.size()][s2.size()];
  }
};
