// Small: 4ms; Large: 48ms
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool pos = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);
        long long dividend_tmp = dividend, divisor_tmp = divisor, x, d;
        dividend_tmp = abs(dividend_tmp);
        divisor_tmp = abs(divisor_tmp);
        int res = 0;
        while (dividend_tmp >= divisor_tmp) {
            x = 1;
            d = divisor_tmp;
            while (d <= dividend_tmp) {
                x <<= 1;
                d <<= 1;
            }
            res += x >> 1;
            dividend_tmp -= d >> 1;
        }
        if (!pos) {
            res = -res;
        }
        return res;
    }
};
