// Small: 8ms; Large: 72ms
class Solution {
 public:
  int minPathSum(vector<vector<int> > &grid) {
    if (grid.empty()) {
      return 0;
    }
    int h = grid.size(), w = grid[0].size();
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        int cost = 0;
        if (i > 0) {
          cost = grid[i - 1][j];
        }
        if (j > 0 && (cost == 0 || cost > grid[i][j - 1])) {
          cost = grid[i][j - 1];
        }
        grid[i][j] += cost;
      }
    }
    return grid[h - 1][w - 1];
  }
};
