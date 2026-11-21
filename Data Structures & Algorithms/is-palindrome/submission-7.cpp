class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size();
        while (l < r) {
            while (l < s.size() && !isalnum(s[l])) {
                l++;
            }

            while (r >= 0 && !isalnum(s[r])) {
                r--;
            }

            if (l > r || l >= s.size() || r < 0) {
                break;
            }

            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            
            l++;
            r--;
        }
        
        return true;
    }
};
