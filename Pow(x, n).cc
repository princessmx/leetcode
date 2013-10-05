class Solution {
public:
    double pow(double x, int n) {
        long long m = n;
        bool neg = false;
        if (m < 0) {
            m = -m;
            neg = true;
        }
        double res = 1;
        while (m) {
            if (m & 1) {
                res *= x;
            }
            x *= x;
            m >>= 1;
        }
        if (neg) {
            res = 1 / res;
        }
        return res;
    }
};
