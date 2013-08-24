// Small: 8ms; Large: 140ms
class Solution {
 public:
  int numDistinct(string S, string T) {
    if (S.empty() || T.empty()) {
      return 0;
    }
    vector<vector<int> > count(S.size(), vector<int>(T.size(), 0));
    for (int j = 0; j < T.size(); j++) {
      for (int i = j; i < S.size(); i++) {
        if (i != 0) {
          count[i][j] = count[i - 1][j];
        }
        if (j == 0) {
          count[i][j] += (S[i] == T[j]);
        } else {
          if (S[i] == T[j]) {
            count[i][j] += count[i - 1][j - 1];
          }
        }
      }
    }
    return count[S.size() - 1][T.size() - 1];
  }
};
