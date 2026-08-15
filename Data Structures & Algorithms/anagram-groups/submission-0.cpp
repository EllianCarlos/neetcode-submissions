class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;

        for (string s : strs) {
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            
            if (anagrams.find(sortedS) != anagrams.end()) {
                anagrams[sortedS].push_back(s);
            } else {
                anagrams[sortedS] = {s};
            }
        }

        vector<vector<string>> ans;
        
        for (auto anagramPair : anagrams) {
            ans.push_back(anagramPair.second);
        }

        return ans;
    }
};
