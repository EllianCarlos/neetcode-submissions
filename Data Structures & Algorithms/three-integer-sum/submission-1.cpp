class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        set<vector<int>> ans;

        for (int i = 0; i < nums.size(); ++i) {
            int l = 0, r = nums.size() - 1;

            while (l < r) {
                int sum = nums[l] + nums[r];

                if (sum + nums[i] > 0) {
                    r--;
                } else if (sum + nums[i] < 0) {
                    l++;
                } else {
                    if (l != i && r != i) {
                        vector<int> res = vector<int>({nums[l], nums[r], nums[i]});
                        sort(res.begin(), res.end());
                        ans.insert(res);
                    }

                    l++;
                }
            }
        }

        vector<vector<int>> ans_fil;
        for (vector<int> a : ans) {
            ans_fil.push_back(a);
        }
        
        return ans_fil;
    }
};
