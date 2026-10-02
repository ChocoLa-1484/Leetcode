class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        if (s1.length() < s2.length()) swap(s1, s2);
        int m = s2.length();
        vector<int> dp(m + 1);
        for (int i = 1; i <= m; i++)
            dp[i] += dp[i - 1] + s2[i - 1];
        for (const char c : s1) {
            int pre = dp[0];
            dp[0] += c;
            for (int j = 0; j < m; j++) {
                pre = exchange(dp[j + 1], c == s2[j] ? pre : min(dp[j + 1] + c, dp[j] + s2[j]));
            }
        }
        return dp[m];
    }
};

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        if (s1.length() < s2.length()) swap(s1, s2);
        int sum = ranges::fold_left(s1, 0, plus{}) + ranges::fold_left(s2, 0, plus{});
        int m = s2.length();
        vector<int> dp(m + 1);
        for (const char c : s1) {
            for (int j = 0, pre = 0; j < m; j++) {
                pre = exchange(dp[j + 1], c == s2[j] ? pre + c : max(dp[j + 1], dp[j]));
            }
        }
        return sum - 2 * dp[m];
    }
};