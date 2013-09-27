class Solution {
public:
    Solution() {
        digit_letter_map_['0'] = " ";
        digit_letter_map_['2'] = "abc";
        digit_letter_map_['3'] = "def";
        digit_letter_map_['4'] = "ghi";
        digit_letter_map_['5'] = "jkl";
        digit_letter_map_['6'] = "mno";
        digit_letter_map_['7'] = "pqrs";
        digit_letter_map_['8'] = "tuv";
        digit_letter_map_['9'] = "wxyz";
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string path;
        letterCombinations(digits, 0, &path, &res);
        return res;
    }
private:
    void letterCombinations(const string& digits, int index, string* path, vector<string>* res) {
        if (index >= digits.size()) {
            res->push_back(*path);
            return;
        }
        const string& letters = digit_letter_map_[digits[index]];
        for (int i = 0; i < letters.size(); i++) {
            path->push_back(letters[i]);
            letterCombinations(digits, index + 1, path, res);
            path->pop_back();
        }
    }
    map<char, string> digit_letter_map_;
};
