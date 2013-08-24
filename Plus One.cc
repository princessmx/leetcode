// Small: 4ms; Large: 16ms
class Solution {
 public:
  vector<int> plusOne(vector<int> &digits) {
    stack<int> digit_stack;
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; i--) {
      digits[i] += carry;
      carry = digits[i] / 10;
      digits[i] %= 10;
      digit_stack.push(digits[i]);
    }
    if (carry) {
      digit_stack.push(carry);
    }
    vector<int> res;
    while (!digit_stack.empty()) {
      res.push_back(digit_stack.top());
      digit_stack.pop();
    }
    return res;
  }
};
