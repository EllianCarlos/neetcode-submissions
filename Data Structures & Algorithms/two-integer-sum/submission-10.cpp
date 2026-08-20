class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> missingToTarget;

        for (int i = 0; i < nums.size(); ++i) {
        
            if (missingToTarget.find(nums[i]) != missingToTarget.end()) {
                return {missingToTarget[nums[i]], i};
            }

            missingToTarget[target - nums[i]] = i;
        }

        return {-1,-1};
    }
};
