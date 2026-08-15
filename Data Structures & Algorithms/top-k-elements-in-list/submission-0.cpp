class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;

        for (auto& num : nums) {
            freqMap[num]++;
        }

        priority_queue<pair<int, int>> pq;
        for (auto& p : freqMap) {
            pq.push(make_pair(p.second, p.first));
        }

        vector<int> ans(k, 0);
        for (int i = 0; i < k; ++i) {
            ans[i] = pq.top().second;
            pq.pop();
        }

        return ans;
    }
};
