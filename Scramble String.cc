// Small: 12ms; Large: 92ms
#define MAX_STR_LEN 100

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int sz = s1.size();
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                is_scramble[1][i][j] = (s1[i] == s2[j]);
            }
        }
        
        for (int len = 2; len <= sz; len++) {
            for (int i = 0; i <= sz - len; i++) {
                for (int j = 0; j <= sz - len; j++) {
                    is_scramble[len][i][j] = false;
                    for (int l_len = 1; l_len <= len; l_len++) {
                        int r_len = len - l_len;
                        bool r1 = is_scramble[l_len][i][j] && is_scramble[r_len][i + l_len][j + l_len];
                        bool r2 = is_scramble[l_len][i][j + r_len] && is_scramble[r_len][i + l_len][j];
                        is_scramble[len][i][j] = r1 || r2;
                        if (is_scramble[len][i][j]) {
                            break;
                        }
                    }
                }
            }
        }
        
        return is_scramble[sz][0][0];
    }
private:
    bool is_scramble[MAX_STR_LEN][MAX_STR_LEN][MAX_STR_LEN];
};
