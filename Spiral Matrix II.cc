class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n));
        int l = 0, r = n - 1, k = 1;
        while (l <= r) {
            for (int i = l; i <= r; i++) {
                res[l][i] = k++;
            }
            for (int i = l + 1; i <= r; i++) {
                res[i][r] = k++;
            }
            for (int i = r - 1; i >= l; i--) {
                res[r][i] = k++;
            }
            for (int i = r - 1; i >= l + 1; i--) {
                res[i][l] = k++;
            }
            l++;
            r--;
        }
        return res;
    }
};
