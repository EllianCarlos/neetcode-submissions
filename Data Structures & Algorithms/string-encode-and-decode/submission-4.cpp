class Solution {
public:
    string encode(vector<string>& strs) {
        if (strs.empty()) return "";

        return accumulate(
            next(strs.begin()),
            strs.end(),
            strs.front() + this->delim,
            [=](string acc, const string& s) {
                return move(acc) + s + delim;
            }
        );
    }

    vector<string> decode(string s) {
        if (s == "") return {};

        vector<string> ans;
        size_t start = 0;
        size_t end = s.find(delim);

        while (end != string_view::npos) {
            ans.push_back(s.substr(start, end - start));
            start = end + delim.length();
            end = s.find(delim, start);
        }
        // ans.push_back(s.substr(start));

        return ans;
    }
private:
    const string delim = "0,kl"; 
};
