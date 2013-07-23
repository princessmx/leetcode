// Small: 4ms; Large: 40ms
class Solution {
 public:
  int minimumTotal(vector<vector<int> > &triangle) {
    vector<int> min_sum(triangle[triangle.size() - 1]);
    for (int i = triangle.size() - 2; i >= 0; i--) {
      for (int j = 0; j < triangle[i].size(); j++) {
        min_sum[j] = std::min(min_sum[j], min_sum[j + 1]) + triangle[i][j];
      }
    }
    return min_sum[0];
  }
};
