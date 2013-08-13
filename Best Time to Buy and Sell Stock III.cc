// Small: 8ms; Large: 44ms
class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int sz = prices.size();
    int *max_end_with = new int[sz];
    int min_price = INT_MAX, max_profit1 = 0;
    for (int i = 0; i < sz; i++) {
      int profit = prices[i] - min_price;
      if (max_profit1 < profit) {
        max_profit1 = profit;
      }
      max_end_with[i] = max_profit1;
      if (min_price > prices[i]) {
        min_price = prices[i];
      }
    }
    int max_price = -1, max_profit2 = 0, max_profit = 0;
    for (int i = sz - 1; i >= 0; i--) {
      int profit = max_price - prices[i];
      if (max_profit2 < profit) {
        max_profit2 = profit;
      }
      profit = max_profit2 + max_end_with[i];
      if (max_profit < profit) {
        max_profit = profit;
      }
      if (max_price < prices[i]) {
        max_price = prices[i];
      }
    }
    delete [] max_end_with;
    return max_profit;
  }
};
