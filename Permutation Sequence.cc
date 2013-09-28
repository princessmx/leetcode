class Solution {
public:
    Solution() {
        factorials_.push_back(1);
        for (int i = 1; i <= 9; i++) {
            factorials_.push_back(factorials_[i - 1] * i);
        }
    }
    string getPermutation(int n, int k) {
        set<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.insert(i);
        }
        string res;
        while (k && n) {
            int num = (k - 1) / factorials_[n - 1];
            int i = 0;
            set<int>::iterator it = nums.begin();
            while (i < num) {
                i++;
                it++;
            }
            res.push_back(*it + '0');
            nums.erase(it);
            k = (k - 1) % factorials_[n - 1] + 1;
            n--;
        }
        return res;
    }
private:
    vector<int> factorials_;
};
