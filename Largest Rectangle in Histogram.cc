// Small: 12ms; Large: 112ms
class Solution {
 public:
  int largestRectangleArea(vector<int> &height) {
    int max_area = 0;
    stack<int> s;
    for (int i = 0; i < height.size(); i++) {
      if (s.empty()) {
        s.push(i);
      } else {
        while (!s.empty()) {
          int top_index = s.top();
          if (height[top_index] <= height[i]) {
            s.push(i);
            break;
          } else {
            s.pop();
            int left_width = s.empty() ? top_index : top_index - s.top() - 1;
            int right_width = i - top_index - 1;
            max_area = max(max_area, (left_width + right_width + 1) * height[top_index]);
          }
        }
        if (s.empty()) {
          s.push(i);
        }
      }
    }
    int right = s.empty() ? 0 : s.top(), index;
    while (!s.empty()) {
      index = s.top();
      s.pop();
      int left_width = s.empty() ? index : index - s.top() - 1;
      int right_width = right - index;
      max_area = max(max_area, (left_width + right_width + 1) * height[index]);
    }
    return max_area;
  }
};
