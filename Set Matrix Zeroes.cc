class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }
        int r = matrix.size(), c = matrix[0].size();
        vector<bool> r_zero(r, false), c_zero(c, false);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == 0) {
                    r_zero[i] = true;
                    c_zero[j] = true;
                }
            }
        }
        for (int i = 0; i < r; i++) {
            if (r_zero[i]) {
                for (int j = 0; j < c; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < c; i++) {
            if (c_zero[i]) {
                for (int j = 0; j < r; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
    }
};
