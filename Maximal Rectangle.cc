// Small: 12ms; Large: 76ms
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int max_rec = 0;
        if (matrix.empty() || matrix[0].empty()) {
            return max_rec;
        }
        vector<int> histogram(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '1') {
                    histogram[j]++;
                } else {
                    histogram[j] = 0;
                }
            }
            int rec = maximalRectangle(histogram);
            if (max_rec < rec) {
                max_rec = rec;
            }
        }
        return max_rec;
    }
private:
    int maximalRectangle(const vector<int> &histogram) {
        int max_rec = 0, top_index, index, left_width, right_width, rec;
        stack<int> s;
        for (int i = 0; i < histogram.size(); i++) {
            if (s.empty()) {
                s.push(i);
            } else {
                while (!s.empty()) {
                    top_index = s.top();
                    if (histogram[top_index] <= histogram[i]) {
                        s.push(i);
                        break;
                    } else {
                        s.pop();
                        left_width = s.empty() ? top_index : top_index - s.top() - 1;
                        right_width = i - top_index - 1;
                        rec = histogram[top_index] * (left_width + right_width + 1);
                        if (max_rec < rec) {
                            max_rec = rec;
                        }
                    }
                }
                if (s.empty()) {
                    s.push(i);
                }
            }
        }
        top_index = s.empty() ? 0 : s.top();
        while (!s.empty()) {
            index = s.top();
            s.pop();
            left_width = s.empty() ? index : index - s.top() - 1;
            right_width = top_index - index;
            rec = histogram[index] * (left_width + right_width + 1);
            if (max_rec < rec) {
                max_rec = rec;
            }
        }
        return max_rec;
    }
};
