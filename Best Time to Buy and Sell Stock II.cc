// Small: 4ms; Large: 36ms
class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int st = 0, sz = prices.size(), max_profit = 0;
    while (true) {
      while (st < sz - 1 && prices[st] >= prices[st + 1]) {
        st++;
      }
      if (st >= sz - 1) {
        break;
      }
      int min_local = prices[st], max_local = prices[st + 1];
      int i = st + 2;
      while (i < sz && max_local < prices[i]) {
        max_local = prices[i];
        i++;
      }
      st = i;
      max_profit += max_local - min_local;
    }
    return max_profit;
  }
};
