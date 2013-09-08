// Small: 4ms; Large: 40ms
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int l = 0, r = n - 1, mid = 0;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (target < A[mid]) {
                r = mid - 1;
            } else if (target > A[mid]) {
                l = mid + 1;
            } else {
                return mid;
            }
        }
        if (A[mid] < target) {
            return mid + 1;
        }
        return mid;
    }
};
