class Solution {
public:
    bool isPalindrome(string s) {

        int l = 0, r = s.size() - 1;
        
        while (l < r) {
            while (r > l && !isalnum(s[l])) {
                l++;
            }

            while (r > l && !isalnum(s[r])) {
                r--;
            }

            if (tolower(s[r]) != tolower(s[l])) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
};
