class Solution {
public:
    int jump(int A[], int n) {
        if (n == 0) {
            return 0;
        }
        vector<int> d(n, INT_MAX);
        d[0] = 0;
        int max_index = 0;
        for (int i = 0; i < n && max_index < n; i++) {
            if (i > max_index) {
                break;
            }
            int index = min(i + A[i], n - 1);
            for (int j = max_index + 1; j <= index; j++) {
                d[j] = min(d[j], d[i] + 1);
            }
            if (max_index < index) {
                max_index = index;
            }
        }
        return d[n - 1];
    }
};
