class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, 0));
        dp[0][0] = true;
        for (int j = 1; j < n + 1; j++) {
            if (p[j - 1] == '*')    dp[0][j] = dp[0][j - 1];
        }
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = (dp[i][j - 1] || dp[i - 1][j]);
                } else if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
class Solution {
public:
    bool isMatch(string s, string p) {
        int si = 0, pi = 0, match = 0, star = -1;
        int sn = s.length(), pn = p.length();
        while (si < sn) {
            if (pi < pn && (p[pi] == '?' || p[pi] == s[si])) {
                si++, pi++;
            } else if (pi < pn && p[pi] == '*') {
                star = pi++;
                match = si;
            } else if (star != - 1) {
                pi = star + 1;
                si = ++match;
            } else {
                return false;
            }
        }
        while (pi < pn && p[pi] == '*') pi++;
        return pi == pn;
    }
};