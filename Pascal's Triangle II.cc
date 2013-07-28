// Small: 0ms; Large: 12ms
class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    rowIndex++;
    vector<int> res(rowIndex);
  res[0] = 1;
	int mid = 0;
	for (int i = 2; i <= rowIndex; i++) {
	  int cur = mid;
	  if (i & 1) {
	    res[cur] = res[cur - 1] << 1;
		cur--;
	  } else {
	    mid++;
	  }
	  for (; cur > 0; cur--) {
	    res[cur] += res[cur - 1];
	  }
	}
	for (int i = mid; i < rowIndex; i++) {
	  res[i] = res[rowIndex - i - 1];
	}
	return res;
  }
};
