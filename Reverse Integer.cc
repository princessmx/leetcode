// Small: 12ms; Large: 36ms
class Solution {
 public:
  int reverse(int x) {
    int sign = (x >= 0) ? 1 : -1;
    x = abs(x);
    int res = 0;
    while (x) {
      res = res * 10 + x % 10;
      x /= 10;
    }
    return sign * res;
  }
};
