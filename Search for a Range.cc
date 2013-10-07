class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res(2, -1);
        int l = 0, r = n - 1, mid;
        while (l <= r) {
            mid = l + ((r - l) >> 1);
            if (A[mid] >= target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (r < n - 1 && A[r + 1] == target) {
            res[0] = r + 1;
        }
        l = 0, r = n - 1;
        while (l <= r) {
            mid = l + ((r - l) >> 1);
            if (A[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (l > 0 && A[l - 1] == target) {
            res[1] = l - 1;
        }
        return res;
    }
};
