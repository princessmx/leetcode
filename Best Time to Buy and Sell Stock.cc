// Small: 8ms; Large: 56ms
class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int min_value = INT_MAX, max_profit = 0;
    for (int i = 0; i < prices.size(); i++) {
      if (max_profit < prices[i] - min_value) {
        max_profit = prices[i] - min_value;
      }
      if (min_value > prices[i]) {
        min_value = prices[i];
      }
    }
    return max_profit;
  }
};
