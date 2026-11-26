class Solution {
public:
    bool checkString(string s) {
        bool b = false;
        for (const char c : s) {
            if (c == 'a' && b)  return false;
            if (c == 'b')   b = true;
        }
        return true;
    }
};