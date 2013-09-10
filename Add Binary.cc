// Small: 4ms; Large: 28ms
class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty()) {
            return b;
        }
        if (b.empty()) {
            return a;
        }
        int ia = a.size() - 1, ib = b.size() - 1, carry = 0, sum;
        stack<char> tmp_res;
        while (ia >= 0 && ib >= 0) {
            sum = a[ia] - '0' + b[ib] - '0' + carry;
            carry = sum >> 1;
            sum %= 2;
            ia--;
            ib--;
            tmp_res.push(sum + '0');
        }
        while (ia >= 0) {
            sum = a[ia] - '0' + carry;
            carry = sum >> 1;
            sum %= 2;
            tmp_res.push(sum + '0');
            ia--;
        }
        while (ib >= 0) {
            sum = b[ib] - '0' + carry;
            carry = sum >> 1;
            sum %= 2;
            tmp_res.push(sum + '0');
            ib--;
        }
        if (carry) {
            tmp_res.push(carry + '0');
        }
        string res;
        while (!tmp_res.empty()) {
            res.push_back(tmp_res.top());
            tmp_res.pop();
        }
        return res;
    }
};
