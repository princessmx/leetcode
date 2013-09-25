class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        res_.clear();
        tmp_.resize(k);
        n_ = n;
        k_ = k;
        compute_combination(0, 1);
        return res_;
    }
private:
    void compute_combination(int depth, int start) {
        if (depth == k_) {
            res_.push_back(tmp_);
            return;
        }
        int max_num = n_ - k_ + depth + 1;
        for (int i = start; i <= max_num; i++) {
            tmp_[depth] = i;
            compute_combination(depth + 1, i + 1);
        }
    }
    int n_;
    int k_;
    vector<int> tmp_;
    vector<vector<int> > res_;
};
