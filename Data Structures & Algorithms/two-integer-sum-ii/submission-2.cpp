class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 1; i < numbers.size(); ++i) {
            auto it = lower_bound(numbers.begin(), numbers.begin() + i - 1, target - numbers[i]);

            if (*it + numbers[i] == target) {
                return {(int)(it-numbers.begin()) + 1, i + 1};
            }
        }

        return {};
    }
};
