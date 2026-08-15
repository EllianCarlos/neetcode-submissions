class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;

        for (auto& num : nums) {
            freqMap[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);

        for (auto& [num, count] : freqMap) {
            buckets[count].push_back(num);
        }

        vector<int> ans;
        ans.reserve(k);
        for (int i = buckets.size() - 1; i >= 0 && ans.size() < k; --i) {
            for (int num : buckets[i]) {
                ans.push_back(num);
                if (ans.size() == k)
                    break;
            }
        }

        return ans;
    }
};
