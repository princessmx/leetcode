class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *star_p = NULL, *star_s = NULL;
        while (*s) {
            if (*s == *p || *p == '?') {
                s++;
                p++;
            } else if (*p == '*') {
                while (*p == '*') {
                    p++;
                }
                if (!*p) {
                    return true;
                }
                star_p = p;
                star_s = s;
            } else if (star_p) {
                s = ++star_s;
                p = star_p;
            } else {
                return false;
            }
        }
        while (*p) {
            if (*p != '*') {
                return false;
            }
            p++;
        }
        return true;
    }
};
