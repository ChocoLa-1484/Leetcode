class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;
        for (auto i : s) {
            if (i == '*')   len = max(0ll, len - 1);
            else if (i == '#')  len *= 2;
            else if (i != '%')  len++;
        }
        if (k >= len)   return '.';
        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            if (c == '*')   len++;
            else if (c == '#') {
                len >>= 1;
                if (k >= len)   k -= len;
            } else if (c == '%') {
                k = len - 1 - k;
            } else {
                if (k == len - 1)   return c;
                len--;
            }
        }
        return '.';
    }
};