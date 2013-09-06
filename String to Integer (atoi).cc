// Small: 4ms; Large: 40ms
class Solution {
public:
    int atoi(const char *str) {
        int res = 0, sign = 1, i = 0;
        float max_mul = INT_MAX / 10;
        bool out = false;
        while (str[i] && isspace(str[i])) {
            i++;
        }
        if (!isdigit(str[i])) {
            if (str[i] == '-') {
                sign = -1;
                i++;
            } else if (str[i] == '+') {
                i++;
            }
        }
        for (; str[i]; i++) {
            if (!isdigit(str[i])) {
                break;
            }
            if (res > max_mul) {
                out = true;
                res = INT_MAX;
                break;
            }
            res *= 10;
            int digit = str[i] - '0';
            if (res > INT_MAX - digit) {
                out = true;
                res = INT_MAX;
                break;
            }
            res += digit;
        }
        if (sign < 0 && out) {
            res = INT_MIN;
        } else {
            res *= sign;
        }
        return res;
    }
};
