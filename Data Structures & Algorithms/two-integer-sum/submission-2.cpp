class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> complement;

        for (int i = 0; i < nums.size(); ++i) {
            if (complement.find(nums[i]) != complement.end()) {
                return {complement[nums[i]], i};
            }


            complement[target-nums[i]] = i;
        }

        return {};
    }
};
