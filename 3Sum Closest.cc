class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int min_delta = INT_MAX, closet_sum, delta, sum;
        for (int i = 0; i < num.size() - 2; i++) {
            int j = i + 1, k = num.size() - 1;
            while (j < k) {
                sum = num[i] + num[j] + num[k];
                if (sum > target) {
                    delta = sum - target;
                    k--;
                } else if (sum < target) {
                    delta = target - sum;
                    j++;
                } else {
                    return sum;
                }
                if (min_delta > delta) {
                    min_delta = delta;
                    closet_sum = sum;
                }
            }
        }
        return closet_sum;
    }
};
