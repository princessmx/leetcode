class Solution {
public:
    int maxArea(vector<int> &height) {
        int max_area = 0;
        if (height.empty()) {
            return max_area;
        }
        int l = 0, r = height.size() - 1, area;
        while (l < r) {
            if (height[l] < height[r]) {
                area = height[l] * (r - l);
                l++;
            } else if (height[l] > height[r]) {
                area = height[r] * (r - l);
                r--;
            } else {
                area = height[l] * (r - l);
                l++;
                r--;
            }
            if (max_area < area) {
                max_area = area;
            }
        }
        return max_area;
    }
};
