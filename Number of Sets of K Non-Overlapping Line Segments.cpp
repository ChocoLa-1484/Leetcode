class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    int numberOfSets(int n, int k) {
        vector<int> dp(n, 1), prefix(n + 1);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = (prefix[i] + dp[i]) % MOD;
        }
        dp[0] = 0;
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] = (dp[j - 1] + prefix[j]) % MOD;
            }
            for (int j = 0; j < n; j++) {
                prefix[j + 1] = (prefix[j] + dp[j]) % MOD;
            }
        }
        return dp[n - 1];
    }
};