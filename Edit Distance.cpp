class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.length() < word2.length()) swap(word1, word2);
        int m = word2.length();
        vector<int> dp(m + 1);
        ranges::iota(dp, 0);
        for (const char c : word1) {
            for (int j = 0, pre = dp[0]++; j < m; j++) {
                pre = exchange(dp[j + 1], c == word2[j] ? pre : min({dp[j], dp[j + 1], pre}) + 1);
            }
        }
        return dp[m];
    }
};