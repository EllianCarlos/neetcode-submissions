class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();

        vector<int> preProd(n, 1);
        vector<int> postProd(n, 1);

        for (int i = 1, j = n - 2; i < n; ++i) {
            preProd[i] = preProd[i-1] * nums[i - 1];
            postProd[n - 1 - i] = postProd[n - i] * nums[n - i];
        }

        vector<int> result(n , 0);

        for (int i = 0; i < n; ++i) {
            result[i] = preProd[i] * postProd[i];
        }

        return result;
    }
};
