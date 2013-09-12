// Small: 16ms; Large: 20ms
class Solution {
public:
    void sortColors(int A[], int n) {
        int left = 0, right = n - 1;
        for (int i = 0; i <= right; i++) {
            switch (A[i]) {
                case 0:
                    if (left != i) {
                        swap(A[left], A[i]);
                        i--;
                    }
                    left++;
                    break;
                case 2:
                    if (i != right) {
                        swap(A[right], A[i]);
                        i--;
                    }
                    right--;
                    break;
                default:
                    break;
            }
        }
    }
};
