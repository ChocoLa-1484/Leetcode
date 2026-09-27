class Solution {
public:
    static constexpr int INF = 0x3f3f3f3f;
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;
        for (const int x : coins) {
            for (int c = x; c <= amount; c++) {
                dp[c] = min(dp[c], dp[c - x] + 1);
            }
        }
        return dp[amount] == INF ? -1 : dp[amount];
    }
};