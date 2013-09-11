// Small: 8ms; Large: 72ms
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int u = 0, b = matrix.size() - 1, mid;
        while (u <= b) {
            mid = (u + b) >> 1;
            if (matrix[mid][0] > target) {
                b = mid - 1;
            } else if (matrix[mid][0] < target) {
                u = mid + 1;
            } else {
                return true;
            }
        }
        int l = 0, r = matrix[0].size() - 1, row = matrix[mid][0] < target ? mid : mid - 1;
        if (row >= 0) {
            while (l <= r) {
                mid = (l + r) >> 1;
                if (matrix[row][mid] > target) {
                    r = mid - 1;
                } else if (matrix[row][mid] < target) {
                    l = mid + 1;
                } else {
                    return true;
                }
            }
        }
        return false;
    }
};
