class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        int chars[26];
        for (int i = 0; i < 26; ++i) {
            chars[i] = 0;
        }

        for (int i = 0; i < s.size(); ++i) {
            chars[int('z' - s[i])]++;
        }


        for (int i = 0; i < t.size(); ++i) {
            chars[int('z' - t[i])]--;
            cout << t[i] << " index " << (int)'z'-t[i] << " " << chars[(int)('z' - t[i])] << endl;
            if (chars[int('z' - t[i])] < 0) {
                return false;
            }
        }

        return true;
    }
};
