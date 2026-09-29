class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        vector dp(n + 1, vector<int>(m + 1));
        for (int j = 0; j <= m; j++)    dp[0][j] = j;
        for (int i = 1; i <= n; i++)    dp[i][0] = i;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i + 1][j + 1] = str1[i] == str2[j] ? dp[i][j] + 1 : min(dp[i][j + 1], dp[i + 1][j]) + 1;
            }
        }
        int i = n - 1, j = m - 1;
        string ans;
        while (i >= 0 && j >= 0) {
            if (str1[i] == str2[j]) {
                ans += str1[i];
                i--, j--;
            } else if (dp[i + 1][j + 1] == dp[i][j + 1] + 1) {
                ans += str1[i--];
            } else {
                ans += str2[j--];
            }
        }
        ranges::reverse(ans);
        return str1.substr(0, i + 1) + str2.substr(0, j + 1) + ans;
    }
};