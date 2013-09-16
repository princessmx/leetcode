// Small: 4ms; Large: 12ms
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<Number> nums;
        for (int i = 0; i < numbers.size(); i++) {
            nums.push_back(Number(numbers[i], i + 1));
        }
        sort(nums.begin(), nums.end());
        vector<int> res(2);
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int sum = nums[l].val + nums[r].val;
            if (sum > target) {
                r--;
            } else if (sum < target) {
                l++;
            } else {
                res[0] = min(nums[l].index, nums[r].index);
                res[1] = max(nums[l].index, nums[r].index);
                break;
            }
        }
        return res;
    }
private:
    struct Number {
        Number(int _val, int _index) : val(_val), index(_index) {}
        
        bool operator<(const Number &other) const {
            return val < other.val || (val == other.val && index < other.index);
        }
        
        int val;
        int index;
    };
};
