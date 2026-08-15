class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> complement;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (complement.find(target - nums[i]) != complement.end()) {
                return {complement[target-nums[i]], i};
            }

            complement[nums[i]] = i;
        }

        return {-1, -1};
    }
};
