// Small: 16ms; Large: 92ms
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        vector<int> trash;
        for (int i = 2; i < n; i++) {
            if (A[i] == A[i - 2]) {
                trash.push_back(i);
            }
        }
        for (int i = 0; i < trash.size(); i++) {
            int end = (i == trash.size() - 1) ? n : trash[i + 1];
            for (int j = trash[i]; j < end && j + 1 < n; j++) {
                A[j - i] = A[j + 1];
            }
        }
        return n - trash.size();
    }
};
