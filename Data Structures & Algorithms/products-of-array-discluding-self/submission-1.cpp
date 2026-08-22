class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);

        for (int i = 1, j = n - 2; i < nums.size() && j >= 0; ++i, --j) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
            suffix[j] = suffix[j + 1] * nums[j + 1];
        }

        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            ans[i] = prefix[i] * suffix[i];
        }
        return ans;
    }
};
