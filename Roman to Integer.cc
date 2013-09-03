// Small: 12ms; Large: 192ms
class Solution {
 public:
  Solution() {
    symbols_.push_back(1000);
    symbols_.push_back(500);
    symbols_.push_back(100);
    symbols_.push_back(50);
    symbols_.push_back(10);
    symbols_.push_back(5);
    symbols_.push_back(1);
    symbols_index_['M'] = 0;
    symbols_index_['D'] = 1;
    symbols_index_['C'] = 2;
    symbols_index_['L'] = 3;
    symbols_index_['X'] = 4;
    symbols_index_['V'] = 5;
    symbols_index_['I'] = 6;
  }

  int romanToInt(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
      int index = symbols_index_[s[i]];
      if (i == s.size() - 1 || index <= symbols_index_[s[i + 1]]) {
        res += symbols_[index];
      } else {
        res -= symbols_[index];
      }
    }
    return res;
  }
 private:
  vector<int> symbols_;
  map<char, int> symbols_index_;
};
