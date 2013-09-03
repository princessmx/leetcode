// Small: 16ms; Large: 24ms
class Solution {
 public:
  string longestCommonPrefix(vector<string> &strs) {
    string res;
    if (strs.empty()) {
      return res;
    }
    int i = 0;
    bool common = true;
    while (common) {
      for (int j = 0; j < strs.size(); j++) {
        if (strs[j].size() < i + 1 || strs[j][i] != strs[0][i]) {
          common = false;
          break;
        }
      }
      if (common) {
        res.push_back(strs[0][i]);
        i++;
      }
    }
    return res;
  }
};
