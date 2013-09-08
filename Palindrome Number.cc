// Small: 12ms; Large: 336ms
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        long reversed_x = reverseNum(x);
        return reversed_x == x;
    }
private:
    long reverseNum(long x) {
        int res = 0;
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};
