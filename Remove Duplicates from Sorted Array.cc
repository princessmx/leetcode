// Small: 12ms; Large: 76ms
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) {
            return 0;
        }
        vector<int> trash;
        int cur = A[0];
        for (int i = 1; i < n; i++) {
            if (A[i] == cur) {
                trash.push_back(i);
            } else {
                cur = A[i];
            }
        }
        for (int i = 0; i < trash.size(); i++) {
            int end = (i == trash.size() - 1) ? n : trash[i + 1];
            for (int j = trash[i] - i; j < end && j + i + 1 < n; j++) {
                A[j] = A[j + i + 1];
            }
        }
        return n - trash.size();
    }
};
