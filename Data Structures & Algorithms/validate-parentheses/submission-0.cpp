class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for (char c : s) {
            if (isClosing(c)) {
                if (brackets.empty()) {
                    return false;
                }

                char openC = brackets.top();
                brackets.pop();

                if (closingToOpen[c] != openC) {
                    return false;
                }
            } else {
                brackets.push(c);
            }
        }

        return brackets.empty();
    }
private:
    bool isClosing(char c) {
        return c == '}' || c == ')' || c == ']';
    }
    unordered_map<char, char> closingToOpen = { { '}', '{' }, {')', '('}, {']', '['} };
};
