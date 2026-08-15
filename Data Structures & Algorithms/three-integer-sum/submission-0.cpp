class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, vector<pair<int, int>>> complement;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j) continue;
                complement[0 - nums[i] - nums[j]].emplace_back(i, j);
            }
        }

        set<vector<int>> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (complement.find(nums[i]) != complement.end()) {
                vector<pair<int, int>> vcp = complement[nums[i]];

                for (pair<int, int> cp : vcp) {
                    if (cp.first == i || cp.second == i) {
                        continue;
                    }

                    vector<int> current = vector<int>({nums[cp.first], nums[cp.second], nums[i]});
                    sort(current.begin(), current.end());
                    ans.insert(current);
                }
            }
        }

        vector<vector<int>> response;
        for (vector<int> v : ans) {
            response.push_back(v); 
        }
        
        return response;
    }
};
