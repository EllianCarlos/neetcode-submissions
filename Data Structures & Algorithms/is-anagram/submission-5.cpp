class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> freqMap;

        for (const char& c : s) {
            freqMap[c]++;
        }

        for (const char& c : t) {
            freqMap[c]--;

            if (freqMap[c] < 0) {
                return false;
            }
        }

        return true;
    }
};
