class Solution {
public:
    bool canJump(int A[], int n) {
        int max_index = 0;
        for (int i = 0; i < n - 1; i++) {
            if (i > max_index) {
                return false;
            }
            int jump_index = i + A[i];
            if (max_index <= jump_index) {
                max_index = jump_index;
                if (max_index >= n - 1) {
                    return true;
                }
            }
        }
        return max_index >= n - 1;
    }
};
