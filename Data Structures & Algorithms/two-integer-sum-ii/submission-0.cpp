class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> umap;

        for (int i = 0; i < numbers.size(); ++i) {
            if (umap.find(numbers[i]) != umap.end()) {
                return {umap[numbers[i]] + 1, i + 1};
            }
            umap[target - numbers[i]] = i;
        }

        return {};
    }
};
