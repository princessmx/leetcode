// Small: 8ms; Large: 20ms
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int last_index = n - 1;
        while (A[last_index] == elem) {
            last_index--;
        }
        for (int i = 0; i <= last_index; i++) {
            if (A[i] == elem) {
                swap(A[i], A[last_index]);
                last_index--;
                while (A[last_index] == elem) {
                    last_index--;
                }
            }
        }
        return last_index + 1;
    }
};
