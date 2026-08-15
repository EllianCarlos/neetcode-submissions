class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> sets;

        for (auto n : nums) {
            sets.insert(n);
        }

        return sets.size() != nums.size();
    }
};