class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;

        for (const string& s : strs) {
            string key(26, 0);
            for (char c : s) {
                key[c - 'a']++;
            }
            
            anagrams[key].push_back(s);
        }

        vector<vector<string>> ans;
        
        for (auto& anagramPair : anagrams) {
            ans.push_back(anagramPair.second);
        }

        return ans;
    }
};
