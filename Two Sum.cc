// Small: 4ms; Large: 16ms
class Solution {
 public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<Number> nums;
    for (int i = 0; i < numbers.size(); i++) {
      nums.push_back(Number(numbers[i], i + 1));
    }
    sort(nums.begin(), nums.end());
    vector<int> res(2);
    for (int i1 = 0; i1 < nums.size(); i1++) {
      int i2 = bsearch(nums, target - nums[i1].num, i1);
      if (i2 >= 0) {
        if (nums[i1].index < nums[i2].index) {
          res[0] = nums[i1].index;
          res[1] = nums[i2].index;
        } else {
          res[0] = nums[i2].index;
          res[1] = nums[i1].index;
        }
        break;
      }
    }
    return res;
  }
 private:
  struct Number {
    Number(int _num, int _index)
        : num(_num), index(_index) {}

    bool operator<(const Number &other) const {
      return num < other.num || (num == other.num && index < other.index);
    }

    int num;
    int index;
  };

  int bsearch(const vector<Number>& nums, int num, int black_index) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (nums[mid].num < num) {
        l = mid + 1;
      } else if (nums[mid].num > num) {
        r = mid - 1;
      } else {
        if (mid == black_index && nums[mid + 1].num == num) {
          return mid + 1;
        } else {
          return mid;
        }
      }
    }
    return -1;
  }
};
