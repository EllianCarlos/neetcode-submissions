class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        
        for (const string& str : strs) {
            string hashedStr(26, 0);
            for (char c : str) {
                hashedStr[c - 'a']++;
            }

            anagrams[hashedStr].push_back(str);
        }

        vector<vector<string>> ans;
        for (const auto& anagram : anagrams) {
            ans.push_back(anagram.second);
        }
        return ans;
    }
};
