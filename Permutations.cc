class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        result_.clear();
        if (num.empty()) {
            return result_;
        }
        exist_.resize(num.size(), false);
        permutation_.resize(num.size());
        permute(num, 0);
        return result_;
    }
private:
    void permute(const vector<int> &num, int index) {
        if (index == num.size()) {
            result_.push_back(permutation_);
            return;
        }
        for (int i = 0; i < num.size(); i++) {
            if (!exist_[i]) {
                permutation_[index] = num[i];
                exist_[i] = true;
                permute(num, index + 1);
                exist_[i] = false;
            }
        }
    }
    vector<bool> exist_;
    vector<vector<int> > result_;
    vector<int> permutation_;
};
