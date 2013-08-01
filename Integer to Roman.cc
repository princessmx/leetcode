// Small: 12ms; Large: 168ms
class Solution {
 public:
  string intToRoman(int num) {
    num_map_[1] = "I";
    num_map_[4] = "IV";
    num_map_[5] = "V";
    num_map_[9] = "IX";
    num_map_[10] = "X";
    num_map_[40] = "XL";
    num_map_[50] = "L";
    num_map_[90] = "XC";
    num_map_[100] = "C";
    num_map_[400] = "CD";
    num_map_[500] = "D";
    num_map_[900] = "CM";
    num_map_[1000] = "M";
    string res;
    for (map<int, string, greater<int> >::iterator it = num_map_.begin();
         it != num_map_.end() && num;
         it++) {
      int count = num / it->first;
      for (int i = 0; i < count; i++) {
        res.append(it->second);
      }
      num %= it->first;
    }
    return res;
  }
 private:
  map<int, string, greater<int> > num_map_;
};
