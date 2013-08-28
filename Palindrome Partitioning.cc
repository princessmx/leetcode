// Small: 12ms; Large: 52ms
class Solution {
 public:
  Solution() : char_positions_(vector<vector<int> >(CHAR_MAX, vector<int>())) {}

  vector<vector<string>> partition(string s) {
    for (int i = 0; i < CHAR_MAX; i++) {
      char_positions_[i].clear();
    }
    for (int i = 0; i < s.size(); i++) {
      char_positions_[s[i]].push_back(i);
    }
    res_.clear();
    vector<string> dump;
    partition(s, 0, &dump);
    return res_;
  }
 private:
  bool isPalindrome(const string &s, int start, int end) {
    if (start == end) {
      return true;
    }
    int half = (end - start + 1) >> 1;
    for (int i = 0; i <= half; i++) {
      if (s[start + i] != s[end - i]) {
        return false;
      }
    }
    return true;
  }
  void partition(const string &s, int start, vector<string> *res) {
    if (start >= s.size()) {
      res_.push_back(*res);
      return;
    }
    vector<int> &positions = char_positions_[s[start]];
    for (int i = 0; i < positions.size(); i++) {
      if (start > positions[i] || !isPalindrome(s, start, positions[i])) {
        continue;
      }
      res->push_back(s.substr(start, positions[i] - start + 1));
      partition(s, positions[i] + 1, res);
      res->pop_back();
    }
  }
  vector<vector<int> > char_positions_;
  vector<vector<string> > res_;
};
