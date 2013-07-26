// Small: 8ms; Large: 56ms
class Solution {
 public:
  void solve(vector<vector<char> > &board) {
    if (board.size() == 0 || board[0].size() == 0) {
      return;
    }
    int h = board.size(), w = board[0].size();
    queue<Coordinate> coordinates;
    for (int i = 0; i < w; i++) {
      if (board[0][i] == 'O') {
        coordinates.push(Coordinate(0, i));
      }
      if (board[h - 1][i] == 'O') {
        coordinates.push(Coordinate(h - 1, i));
      }
    }
    for (int i = 0; i < h; i++) {
      if (board[i][0] == 'O') {
        coordinates.push(Coordinate(i, 0));
      }
      if (board[i][w - 1] == 'O') {
        coordinates.push(Coordinate(i, w - 1));
      }
    }
    while (!coordinates.empty()) {
      Coordinate c = coordinates.front();
      coordinates.pop();
      board[c.x][c.y] = 'U';
      if (c.x - 1 >= 0 && board[c.x - 1][c.y] == 'O') {
        coordinates.push(Coordinate(c.x - 1, c.y));
      }
      if (c.x + 1 < h && board[c.x + 1][c.y] == 'O') {
        coordinates.push(Coordinate(c.x + 1, c.y));
      }
      if (c.y - 1 >= 0 && board[c.x][c.y - 1] == 'O') {
        coordinates.push(Coordinate(c.x, c.y - 1));
      }
      if (c.y + 1 < w && board[c.x][c.y + 1] == 'O') {
        coordinates.push(Coordinate(c.x, c.y + 1));
      }
    }
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (board[i][j] == 'O') {
          board[i][j] = 'X';
        } else if (board[i][j] == 'U') {
          board[i][j] = 'O';
        }
      }
    }
  }
 private:
  struct Coordinate {
    Coordinate(int _x, int _y)
        : x(_x), y(_y) {}
    int x;
    int y;
  };
};
