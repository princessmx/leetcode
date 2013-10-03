class Solution {
public:
    int singleNumber(int A[], int n) {
        int sz = sizeof(int) * 8;
        vector<int> bits(sz, 0);
        for (int i = 0; i < n; i++) {
            int mask = 1;
            for (int j = 0; j < sz; j++) {
                bits[j] += ((A[i] & mask) >> j);
                mask <<= 1;
            }
        }
        int num = 0, mask = 1;
        for (int i = 0; i < sz; i++) {
            if (bits[i] % 3 != 0) {
                num += mask;
            }
            mask <<= 1;
        }
        return num;
    }
};
