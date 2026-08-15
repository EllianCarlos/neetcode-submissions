class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;

        for (const string& s : strs) {
            string key(26, 0);
            for (char c : s) {
                key[c - 'a']++;
            }

            umap[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (const auto& p : umap) {
            ans.push_back(p.second);
        }
        return ans;
    }
};
