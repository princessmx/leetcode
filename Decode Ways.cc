// Small: 4ms; Large: 16ms
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
        vector<int> count;
        count.push_back(1);
        for (int i = 0; i < s.size(); i++) {
            if (i == 0) {
                if (!isValidEncoding(s, i, 1)) {
                    return 0;
                }
                count.push_back(1);
            } else {
                count.push_back(0);
                if (isValidEncoding(s, i, 1)) {
                    count[i + 1] += count[i];
                }
                if (isValidEncoding(s, i - 1, 2)) {
                    count[i + 1] += count[i - 1];
                }
            }
        }
        return count.back();
    }
private:
    bool isValidEncoding(const string &s, int start, int len) {
        if (len == 1) {
            return s[start] >= '1' && s[start] <= '9';
        } else if (len == 2) {
            return (s[start] == '1' && s[start + 1] >= '0' && s[start + 1] <= '9') ||
                   (s[start] == '2' && s[start + 1] >= '0' && s[start + 1] <= '6');
        }
        return false;
    }
};
