// Small: 4ms; Large: 68ms
class Solution {
 public:
  string convert(string s, int nRows) {
    if (nRows == 1) {
      return s;
    }
    string res;
    int mRows = nRows - 2, head_tail_step = (nRows << 1) - 2, step, reverse_step, index;
    bool reverse = false;
    for (int n = 0; n < nRows; n++) {
      index = n;
      reverse = false;
      step = n << 1;
      reverse_step = (nRows << 1) - (n << 1) - 2;
      while (index < s.size()) {
        res.push_back(s[index]);
        reverse = !reverse;
        if (n == 0 || n == nRows - 1) {
          index += head_tail_step;
        } else {
          if (reverse) {
            index += reverse_step;
          } else {
            index += step;
          }
        }
      }
    }
    return res;
  }
};
