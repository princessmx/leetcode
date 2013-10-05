class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int m = strlen(s), n = strlen(p);
        vector<vector<bool> > match(m + 1, vector<bool>(n + 1, false));
        match[0][0] = true;
        for (int i = 2; i <= n; i++) {
            if (p[i - 1] == '*' && match[0][i - 2]) {
                match[0][i] = true;
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (((s[i - 1] == p[j - 1] || p[j - 1] == '.') && match[i - 1][j - 1]) ||
                    (p[j - 1] == '*' &&
                     (match[i][j - 2] ||
                      (s[i - 1] == p[j - 2] || p[j - 2] == '.') && (match[i - 1][j] || match[i - 1][j - 1] || match[i - 1][j - 2])))) {
                    match[i][j] = true;
                }
            }
        }
        return match[m][n];
    }
};
