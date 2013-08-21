// Small: 140ms; Large: 200ms
class Solution {
 public:
  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int count = m + n;
    int k_start = (count - 1) >> 1, k_count = count ? ((count & 1) ? 1 : 2) : 0;
    vector<int> nums;
    findTheKthNums(A, m, B, n, k_start, k_count, &nums);
    double res = 0;
    for (int i = 0; i < k_count; i++) {
      res += nums[i];
    }
    if (k_count) {
      res /= k_count;
    }
    return res;
  }
 private:
  void findTheKthNums(int A[], int m, int B[], int n, int k_start, int k_count, vector<int> *nums) {
    int count = m + n;
    if (k_count <= 0 || k_count > count) {
      return;
    }
    int al = 0, bl = 0, add, bonus, ak = 0, bk = 0;
    while (k_start > 0 && al < m && bl < n) {
      add = k_start > 1 ? (k_start - 2) >> 1 : 0;
      bonus = k_start > 2 ? (k_start & 1) : 0;
      ak = al + add;
      if (ak >= m) {
        ak = m - 1;
      }
      bk = bl + add;
      if (bk >= n) {
        bk = n - 1;
      }
      if (m - ak >= n - bk) {
        ak += bonus;
      } else {
        bk += bonus;
      }
      if (A[ak] <= B[bk]) {
        k_start -= ak - al + 1;
        al = ak + 1;
      } else if (A[ak] > B[bk]) {
        k_start -= bk - bl + 1;
        bl = bk + 1;
      }
    }
    if (k_start) {
      if (al < m) {
        al += k_start;
      }
      if (bl < n) {
        bl += k_start;
      }
    }
    getTopNums(A, al, m - 1, B, bl, n - 1, k_count, nums);
  }
  void getTopNums(int A[], int al, int ar, int B[], int bl, int br, int count, vector<int> *nums) {
    while (al <= ar && bl <= br && count--) {
      if (A[al] <= B[bl]) {
        nums->push_back(A[al]);
        al++;
      } else {
        nums->push_back(B[bl]);
        bl++;
      }
    }
    while (al <= ar && count--) {
      nums->push_back(A[al]);
      al++;
    }
    while (bl <= br && count--) {
      nums->push_back(B[bl]);
      bl++;
    }
  }
};
