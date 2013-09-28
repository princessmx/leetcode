class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if (matrix.empty()) {
            return res;
        }
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = m - 1, u = 0, b = n - 1;
        while (l <= r && u <= b) {
            for (int i = l; i <= r; i++) {
                res.push_back(matrix[u][i]);
            }
            for (int i = u + 1; i <= b; i++) {
                res.push_back(matrix[i][r]);
            }
            if (b > u) {
                for (int i = r - 1; i >= l; i--) {
                    res.push_back(matrix[b][i]);
                }
            }
            if (l < r) {
                for (int i = b - 1; i >= u + 1; i--) {
                    res.push_back(matrix[i][l]);
                }
            }
            l++;
            r--;
            u++;
            b--;
        }
        return res;
    }
};
