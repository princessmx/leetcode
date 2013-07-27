// Small: 4ms; Large: 16ms
class Solution {
 public:
  vector<vector<int> > generate(int numRows) {
    vector<vector<int> > res;
    for (int i = 1; i <= numRows; i++) {
    res.push_back(vector<int>());
	  int mid = i >> 1;
	  if (i & 1) {
	    mid++;
	  }
	  for (int j = 0; j < i; j++) {
	    if (j == 0) {
		  res[i - 1].push_back(1);
	    } else if (j < mid) {
		  res[i - 1].push_back(res[i - 2][j - 1] + res[i - 2][j]);
		} else {
		  res[i - 1].push_back(res[i - 1][i - j - 1]);
		} 
	  }
	}
	return res;
  }
};
