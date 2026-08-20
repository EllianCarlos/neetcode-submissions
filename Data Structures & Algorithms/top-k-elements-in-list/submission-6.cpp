class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        auto cmp = [&freqMap](int left, int right) { return freqMap[left]<freqMap[right]; };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

        for (int num : nums) {
            freqMap[num]++;
        }

        for (auto p : freqMap) {
            pq.push(p.first);
        }

        vector<int> ans;
        while (k--) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};
