// Small: 4ms; Large: 96ms
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.empty()) {
            if (word.empty()) {
                return true;
            }
            return false;
        }
        int h = board.size(), w = board[0].size();
        if (word.size() > h * w) {
            return false;
        }
        vector<vector<bool> > v(h, vector<bool>(w, false));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (match(board, v, h, w, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool match(const vector<vector<char> > &board, vector<vector<bool> > &v, int h, int w,
               int r, int c, const string &word, int pos) {
        if (pos >= word.size()) {
            return true;
        }
        if (r < 0 || r >= h || c < 0 || c >= w || v[r][c] || board[r][c] != word[pos]) {
            return false;
        }
        v[r][c] = true;
        if (match(board, v, h, w, r - 1, c, word, pos + 1) ||
            match(board, v, h, w, r, c - 1, word, pos + 1) ||
            match(board, v, h, w, r + 1, c, word, pos + 1) ||
            match(board, v, h, w, r, c + 1, word, pos + 1)) {
            return true;
        }
        v[r][c] = false;
        return false;
    }
};
