class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    int countGoodStrings(int low, int high, int zero, int one) {
        int g = gcd(zero, one);
        low = (low - 1) / g + 1;
        high /= g;
        zero /= g;
        one /= g;
        int dp[100001] = {};
        dp[0] = 1;
        int ans = 0;
        for (int i = 1; i <= high; i++) {
            if (i >= zero)  dp[i] = dp[i - zero];
            if (i >= one)   dp[i] = (dp[i] + dp[i - one]) % MOD;
            if (i >= low)   ans = (ans + dp[i]) % MOD;
        }
        return ans;
    }
};