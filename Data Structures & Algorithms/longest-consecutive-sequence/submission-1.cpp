class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int maxStreak = 1;
        int currentStreak = 1;

        for (int i = 0; i < nums.size() - 1; ++i) {
            // If they are duplicates, skip the logic and move on
            if (nums[i] == nums[i + 1]) continue;

            if (nums[i + 1] == nums[i] + 1) {
                currentStreak++;
            } else {
                maxStreak = max(maxStreak, currentStreak);
                currentStreak = 1;
            }
        }

        return max(maxStreak, currentStreak);
    }
};