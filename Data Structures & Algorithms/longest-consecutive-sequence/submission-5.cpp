class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();

        sort(nums.begin(), nums.end());
        
        int currentSize = 1;
        int maxSize = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                currentSize++;
            } else if (nums[i] == nums[i - 1]) {
                continue;
            } else {
                currentSize = 1;
            }
            maxSize = max(maxSize, currentSize);
        }
        return maxSize;
    }
};
