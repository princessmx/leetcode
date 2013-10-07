class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int i1 = -1;
        for (int i = num.size() - 1; i > 0; i--) {
            if (num[i] > num[i - 1]) {
                i1 = i - 1;
                break;
            }
        }
        if (i1 >= 0) {
            int i2 = i1 + 1;
            for (int i = i2 + 1; i < num.size(); i++) {
                if (num[i] > num[i1] && num[i] < num[i2]) {
                    i2 = i;
                }
            }
            swap(num[i1], num[i2]);
            sort(num.begin() + i1 + 1, num.end());
            return;
        }
        int half = num.size() >> 1;
        for (int i = 0; i < half; i++) {
            swap(num[i], num[num.size() - i - 1]);
        }
    }
};
