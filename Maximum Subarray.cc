class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = 0, max_sum = INT_MIN, l = 0, r;
        while (l < n) {
            for (r = l; r < n && sum >= 0; r++) {
                sum += A[r];
                max_sum = max(max_sum, sum);
            }
            sum = 0;
            l = r;
        }
        return max_sum;
    }
};
