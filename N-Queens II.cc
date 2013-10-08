#define MAX_N 50
class Solution {
public:
    int totalNQueens(int n) {
        init(n);
        putQueens(0);
        return total_;
    }
private:
    void init(int n) {
        n_ = n;
        board_.resize(n);
        for (int i = 0; i < n; i++) {
            board_[i].resize(n, '.');
        }
        memset(exist_, false, n_);
        total_ = 0;
    }
    void putQueens(int row) {
        if (row == n_) {
            total_++;
            return;
        }
        for (int i = 0; i < n_; i++) {
            if (isValid(row, i)) {
                board_[row][i] = 'Q';
                exist_[i] = true;
                putQueens(row + 1);
                board_[row][i] = '.';
                exist_[i] = false;
            }
        }
    }
    bool isValid(int row, int col) {
        if (exist_[col]) {
            return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >=0; i--, j--) {
            if (board_[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n_; i--, j++) {
            if (board_[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    int n_;
    vector<string> board_;
    bool exist_[MAX_N];
    int total_;
};
