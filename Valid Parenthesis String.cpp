class Solution {
public:
    bool checkValidString(string s) {
        int a = 0, b = 0;
        for (const char c : s) {
            if (c == '(') {
                a++;
                b++;
            }
            if (c == ')') {
                a--;
                b--;
            }
            if (c == '*') {
                a--;
                b++;
            }
            if (b < 0)  return false;
            a = max(a, 0);
        }
        return a == 0;
    }
};