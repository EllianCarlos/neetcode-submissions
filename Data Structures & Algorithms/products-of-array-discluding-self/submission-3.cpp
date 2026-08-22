class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);

        for (int i = 1; i < nums.size(); ++i) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
            suffix[n - 1 - i] = suffix[n - i] * nums[n - i];
        }

        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            ans[i] = prefix[i] * suffix[i];
        }
        return ans;
    }
};
