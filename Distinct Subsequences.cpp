class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        if (m < n)  return 0;
        vector<unsigned long long> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = min(i, n); j >= max(n - (m - i), 1); j--) {
                if (s[i - 1] == t[j - 1])
                    dp[j] += dp[j - 1];
            }
        }
        return dp[n];
    }
};