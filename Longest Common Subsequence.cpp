class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text2.length();
        vector<int> dp(m + 1);
        for (const char c : text1)
            for (int j = 0, pre = 0; j < m; j++)
                pre = exchange(dp[j + 1], c == text2[j] ? pre + 1 : max(dp[j], dp[j + 1]));
        return dp[m];
    }
};