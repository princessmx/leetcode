// Small: 4ms; Large: 44ms
class Solution {
public:
    bool search(int A[], int n, int target) {
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (A[mid] == target) {
                return true;
            }
            if (A[left] < A[mid]) {
                if (A[left] <= target && A[mid] > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (A[left] > A[mid]) {
                if (A[mid] < target && A[right] >= target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                if (A[mid] != A[right]) {
                    left = mid + 1;
                } else {
                    left++;
                    right--;
                }
            }
        }
        return false;
    }
};
