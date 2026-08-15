class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        int l = 0, r = n - 1;
        int l_max = height[l], r_max = height[r];
        int water_level = 0;

        while (l < r) {
            if (l_max < r_max) {
                l++;
                l_max = max(l_max, height[l]);
                water_level += l_max - height[l];
            } else {
                r--;
                r_max = max(r_max, height[r]);
                water_level += r_max - height[r];
            }
        }

        return water_level;
    }
};
