class Solution {
public:
    int longestValidParentheses(string s) {
        int max_length = 0, last = -1;
        stack<int> lefts;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                lefts.push(i);
            } else {
                if (lefts.empty()) {
                    last = i;
                } else {
                    lefts.pop();
                    if (lefts.empty()) {
                        max_length = max(max_length, i - last);
                    } else {
                        max_length = max(max_length, i - lefts.top());
                    }
                }
            }
        }
        return max_length;
    }
};
