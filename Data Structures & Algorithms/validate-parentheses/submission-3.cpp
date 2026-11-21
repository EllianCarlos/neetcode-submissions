class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;

        for (int i = 0; i < s.size(); ++i) {
            if (!isClosing(s[i])) { 
                parentheses.push(s[i]);
                continue;
            }

            if (parentheses.empty()) return false;

            char top = parentheses.top();
            if (top != getCounterpart(s[i])) {
                return false;
            }
            parentheses.pop();
        }

        return parentheses.empty();
    }
private:
    const char getCounterpart(char& c) {
        // This could become a map to be more readable.
        if (c == '{') return '}';
        if (c == '}') return '{';
        if (c == '(') return ')';
        if (c == ')') return '(';
        if (c == '[') return ']';
        if (c == ']') return '[';
        return ' ';
    }

    bool isClosing(char& c) {
        if (c == '}' || c == ')' || c == ']') {
            return true;
        }

        return false;
    }
};
