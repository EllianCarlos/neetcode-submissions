class Solution {
public:
    string encode(vector<string>& strs) {
        string encodedStrings = "";

        for (string str : strs) {
            encodedStrings += str + separator;
        }

        return encodedStrings;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int idx = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == separator) {
                ans.push_back(s.substr(idx, i - idx));
                idx = i + 1;
            }
        }
        return ans;
    }
private:
    char separator = '\0';
};
