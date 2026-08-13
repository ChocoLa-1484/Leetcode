class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int l = 0, ans = 1;
        int rep = -1;
        int n = s.length();
        for (int r = 1; r < n; r++) {
            if (s[r] == s[r - 1]) {
                l = rep + 1;
                rep = r - 1;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};