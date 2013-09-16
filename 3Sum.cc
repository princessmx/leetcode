// Runtime: 268 ms
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > res;
        int sz = num.size(), sum, i, j, k;
        for (i = 0; i < sz - 2;) {
            j = i + 1, k = sz - 1;
            while (j < k) {
                int sum = num[i] + num[j] + num[k];
                if (sum < 0) {
                    j = getNextNonDupIndex(num, j, 1);
                } else if (sum > 0) {
                    k = getNextNonDupIndex(num, k, -1);
                } else {
                    vector<int> r(3);
                    r[0] = num[i];
                    r[1] = num[j];
                    r[2] = num[k];
                    res.push_back(r);
                    j = getNextNonDupIndex(num, j, 1);
                    k = getNextNonDupIndex(num, k, -1);
                }
            }
            i = getNextNonDupIndex(num, i, 1);
        }
        return res;
    }
private:
    int getNextNonDupIndex(const vector<int> &num, int index, int step) {
        int last;
        do {
            last = index;
            index += step;
        } while (index >= 0 && index < num.size() && num[index] == num[last]);
        return index;
    }
};
