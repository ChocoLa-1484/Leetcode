class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        if (k == 1) return n;
        
        auto check = [&](int start, int end) -> bool {
            while (start < end) {
                if (s[start++] != s[--end]) return false;
            }
            return true;
        };
        const int a[2] = {k, k + 1};
        int ans = 0;
        for (int i = 0, step = 1; i <= n - k; i += step, step = 1) {
            for (const int len : a) {
                if (i + len <= n && check(i, i + len)) {
                    ans++;
                    step = len;
                    break;
                }
            }
        }
        return ans;
    }
};