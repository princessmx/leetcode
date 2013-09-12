// Small: 16ms; Large: 36ms
class Solution {
public:
    int search(int A[], int n, int target) {
        int sep_index = findPos(A, 0, n - 1);
        if (sep_index > 0) {
            int index = binarySearch(A, 0, sep_index - 1, target);
            if (index >= 0) {
                return index;
            }
            return binarySearch(A, sep_index, n - 1, target);
        }
        return binarySearch(A, 0, n - 1, target);
    }
private:
    int findPos(int A[], int left, int right) {
        if (left > right) {
            return -1;
        }
        if (left == right) {
            return left;
        }
        int mid = (left + right) >> 1;
        if (A[left] <= A[mid]) {
            int pos = findPos(A, mid + 1, right);
            if (pos < 0 || A[left] < A[pos]) {
                return left;
            }
            return pos;
        }
        return findPos(A, left, mid);
    }
    int binarySearch(int A[], int left, int right, int target) {
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (A[mid] < target) {
                left = mid + 1;
            } else if (A[mid] > target) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
