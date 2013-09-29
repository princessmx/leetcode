class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        subset_.clear();
        subsets_.clear();
        sort(S.begin(), S.end());
        subsets(S, 0);
        return subsets_;
    }
private:
    void subsets(const vector<int> &S, int index) {
        if (index == S.size()) {
            subsets_.push_back(subset_);
            return;
        }
        subset_.push_back(S[index]);
        subsets(S, index + 1);
        subset_.pop_back();
        subsets(S, index + 1);
    }
    vector<int> subset_;
    vector<vector<int> > subsets_;
};
