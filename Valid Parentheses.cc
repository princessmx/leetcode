// Small: 12ms; Large: 12ms
class Solution {
 public:
  bool isValid(string s) {
    stack<char> match_stack;
    for (int i = 0; i < s.size(); i++) {
      switch (s[i]) {
        case '(':
        case '{':
        case '[':
          match_stack.push(s[i]);
          break;
        case ')':
        case '}':
        case ']':
          if (!match_stack.empty()) {
            if (!isMatch(match_stack.top(), s[i])) {
              return false;
            }
            match_stack.pop();
          } else {
            return false;
          }
          break;
      }
    }
    return match_stack.empty();
  }
 private:
  bool isMatch(char a, char b) const {
    return a == '(' && b == ')' || a == '{' && b == '}' || a == '[' && b == ']';
  }
};
