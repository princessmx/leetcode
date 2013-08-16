// Small: 8ms; Large: 52ms
class Solution {
 public:
  int sqrt(int x) {
    float last, cur = 1;
    do {
      last = cur;
      cur = 0.5 * last + 0.5 * x / last;
    } while (fabs(last - cur) > 10e-5);
    int res = last + 1;
    if (res * res == x) {
      return res;
    }
    res--;
    if (res * res <= x) {
      return res;
    }
    res--;
    return res;
  }
};
