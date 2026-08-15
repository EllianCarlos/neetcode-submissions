class Solution {
public:
    string encode(vector<string>& strs) {
        string encodedStrings = "";

        for (string str : strs) {
            encodedStrings += str;
            encodedStrings += separator;
        }

        return encodedStrings;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string curr = "";
        for (char c : s) {
            if (c != separator) {
                curr += c;
            } else {
                ans.push_back(curr);
                curr = "";
            }
        }
        return ans;
    }
private:
    char separator = '\0';
};
