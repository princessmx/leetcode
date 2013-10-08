class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        init(n);
        putQueens(0);
        return solutions_;
    }
private:
    void init(int n) {
        n_ = n;
        solutions_.clear();
        solution_.resize(n);
        for (int i = 0; i < n; i++) {
            solution_[i].resize(n, '.');
        }
        exist_.resize(n, false);
    }
    void putQueens(int row) {
        if (row == n_) {
            solutions_.push_back(solution_);
            return;
        }
        for (int i = 0; i < n_; i++) {
            if (isValid(row, i)) {
                solution_[row][i] = 'Q';
                exist_[i] = true;
                putQueens(row + 1);
                solution_[row][i] = '.';
                exist_[i] = false;
            }
        }
    }
    bool isValid(int row, int col) {
        if (exist_[col]) {
            return false;
        }
        int i = row - 1, j = col - 1;
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (solution_[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n_; i--, j++) {
            if (solution_[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row + 1, j = col - 1; i < n_ && j >= 0; i++, j--) {
            if (solution_[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row + 1, j = col + 1; i < n_ && j < n_; i++, j++) {
            if (solution_[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    int n_;
    vector<vector<string> > solutions_;
    vector<string> solution_;
    vector<bool> exist_;
};
