// Small: 8ms; Large: 24ms
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int n = strlen(haystack), m = strlen(needle);
        if (m == 0) {
            return haystack;
        }
        ComputeNext(needle, m);
        int j = -1;
        for (int i = 0; i < n; i++) {
            while (j >= 0 && haystack[i] != needle[j + 1]) {
                j = next_[j];
            }
            if (haystack[i] == needle[j + 1]) {
                j++;
            }
            if (j == m - 1) {
                return (haystack + i - m + 1);
            }
        }
        return NULL;
    }
private:
    void ComputeNext(char *needle, int len) {
        next_.resize(len);
        next_[0] = -1;
        int k = -1;
        for (int i = 1; i < len; i++) {
            while (k >= 0 && needle[i] != needle[k + 1]) {
                k = next_[k];
            }
            if (needle[i] == needle[k + 1]) {
                k++;
            }
            next_[i] = k;
        }
    }
    vector<int> next_;
};
