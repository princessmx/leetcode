class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = 0;
        if (s != NULL) {
            int i = 0;
            while (true) {
                while (s[i] != '\0' && s[i] == ' ') {
                    i++;
                }
                if (s[i] == '\0') {
                    break;
                }
                len = 0;
                while (s[i] != '\0' && s[i] != ' ') {
                    len++;
                    i++;
                }
            }
        }
        return len;
    }
};
