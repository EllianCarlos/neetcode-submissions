class Solution {
public:
    int maxArea(vector<int>& heights) {
        // Area = height x width
        // in this case as there are two heights:
        // Area = min(height) x width
        // width = index_j - index_i

        int l = 0, r = heights.size() - 1;
        int max_area = -1;

        while (l != r) {
            int area = min(heights[l], heights[r]) * (r - l);
            max_area = max(area, max_area);

            if (heights[l] > heights[r]) {
                r--;
            } else {
                l++;
            }
        }

        return max_area;
    }
};
