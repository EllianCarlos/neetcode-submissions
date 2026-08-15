class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;

        for (string str : strs) {
            string strCopy = str;
            sort(strCopy.begin(), strCopy.end());
            umap[strCopy].push_back(str);
        }

        vector<vector<string>> ans;

        for (const auto & [key, value] : umap) {
            vector<string> block;
            for (string str : value) {
                block.push_back(str);
            }
            ans.push_back(block);
        }

        return ans;
    }
};
