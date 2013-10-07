class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        if (board.size() != 9 || board[0].size() != 9) {
            return false;
        }
        for (int i = 0; i < 9; i++) {
            if (!isValid(board, i, i + 1, 0, 9) ||
                !isValid(board, 0, 9, i, i + 1)) {
                return false;
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!isValid(board, i, i + 3, j, j + 3)) {
                    return false;
                }
            }
        }
        return true;
    }
private:
    bool isValid(vector<vector<char> > &board, int xs, int xe, int ys, int ye) {
        memset(exist_, false, sizeof(exist_));
        for (int x = xs; x < xe; x++) {
            for (int y = ys; y < ye; y++) {
                if (!isdigit(board[x][y])) {
                    continue;
                }
                int num = board[x][y] - '0' - 1;
                if (exist_[num]) {
                    return false;
                }
                exist_[num] = true;
            }
        }
        return true;
    }
    bool exist_[9];
};
