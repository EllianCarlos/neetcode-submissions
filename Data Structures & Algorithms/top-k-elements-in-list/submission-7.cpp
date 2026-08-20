class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& p : freqMap) {
            buckets[p.second].push_back(p.first);
        }

        vector<int> ans;
        for (int freq = buckets.size() - 1; freq >= 1 && ans.size() < k; freq--) {
            for (int num : buckets[freq]) {
                ans.push_back(num);
                if (ans.size() == k) break;
            }
        }

        return ans;
    }
};