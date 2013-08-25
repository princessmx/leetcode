// Small: 8ms; Large: 136ms
class Solution {
 public:
  int minDistance(string word1, string word2) {
    if (word1.empty()) {
      return word2.size();
    }
    if (word2.empty()) {
      return word1.size();
    }
    vector<vector<int> > d(word1.size(), vector<int>(word2.size(), INT_MAX));
    d[0][0] = (word1[0] != word2[0]);
    for (int i = 1; i < word1.size(); i++) {
      d[i][0] = min(i + (word1[i] != word2[0]), d[i - 1][0] + 1);
    }
    for (int i = 1; i < word2.size(); i++) {
      d[0][i] = min(i + (word1[0] != word2[i]), d[0][i - 1] + 1);
    }
    for (int i = 1; i < word1.size(); i++) {
      for (int j = 1; j < word2.size(); j++) {
        d[i][j] = min(d[i - 1][j - 1] + (word1[i] != word2[j]), d[i - 1][j] + 1);
        d[i][j] = min(d[i][j], d[i][j - 1] + 1);
      }
    }
    return d[word1.size() - 1][word2.size() - 1];
  }
};
