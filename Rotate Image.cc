class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int low = 0, high = matrix.size() - 1;
        while (low < high) {
            int sz = high - low;
            for (int i = 0; i < sz; i++) {
                int temp = matrix[low][low + i];
                matrix[low][low + i] = matrix[high - i][low];
                matrix[high - i][low] = matrix[high][high - i];
                matrix[high][high - i] = matrix[low + i][high];
                matrix[low + i][high] = temp;
            }
            low++;
            high--;
        }
    }
};
