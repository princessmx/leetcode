class Solution {
public:
    vector<string> generateParenthesis(int n) {
        n_ = n;
        string parenthesis;
        vector<string> res;
        generateParenthesis(0, 0, &parenthesis, &res);
        return res;
    }
private:
    void generateParenthesis(int left, int right, string *parenthesis, vector<string> *res) {
        if (left == n_ && right == n_) {
            res->push_back(*parenthesis);
            return;
        }
        if (left > right) {
            parenthesis->push_back(')');
            generateParenthesis(left, right + 1, parenthesis, res);
            parenthesis->pop_back();
        }
        if (left < n_) {
            parenthesis->push_back('(');
            generateParenthesis(left + 1, right, parenthesis, res);
            parenthesis->pop_back();
        }
    }
    int n_;
};
