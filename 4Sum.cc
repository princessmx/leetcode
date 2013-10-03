class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        if (num.size() < 4) {
            return res;
        }
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size() - 3; i = next_not_dup_index(num, i)) {
            for (int j = i + 1; j < num.size() - 2; j = next_not_dup_index(num, j)) {
                int sum = num[i] + num[j];
                int k = j + 1, l = num.size() - 1;
                while (k < l) {
                    int sum4 = sum + num[k] + num[l];
                    if (sum4 > target) {
                        l = prev_not_dup_index(num, l);
                    } else if (sum4 < target) {
                        k = next_not_dup_index(num, k);
                    } else {
                        res.push_back(vector<int>(4));
                        vector<int> &r = res.back();
                        r[0] = num[i];
                        r[1] = num[j];
                        r[2] = num[k];
                        r[3] = num[l];
                        k = next_not_dup_index(num, k);
                        l = prev_not_dup_index(num, l);
                    }
                }
            }
        }
        return res;
    }
private:
    int next_not_dup_index(const vector<int> &num, int i) {
        i++;
        while (i < num.size() && num[i] == num[i - 1]) {
            i++;
        }
        return i;
    }
    int prev_not_dup_index(const vector<int> &num, int i) {
        i--;
        while (i >= 0 && num[i] == num[i + 1]) {
            i--;
        }
        return i;
    }
};
