class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> missingToTarget;
        missingToTarget.reserve(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            auto curr = missingToTarget.find(nums[i]);
            if (curr != missingToTarget.end()) {
                return {curr->second, i};
            }

            missingToTarget[target - nums[i]] = i;
        }

        return {-1,-1};
    }
};
