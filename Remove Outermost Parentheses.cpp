class Solution {
public:
    string removeOuterParentheses(string s) {
        int bal = 0;
        string ans;
        for (const char c : s) {
            bal += c == '(' ? 1 : -1;
            if (bal == 1 && c == '(' || bal == 0 && c == ')')
                continue;
            ans += c;
        }
        return ans;
    }
};