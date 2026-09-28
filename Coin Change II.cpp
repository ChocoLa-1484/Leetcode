class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned> dp(amount + 1, 0);
        dp[0] = 1;
        for (const int x : coins) {
            for (int i = x; i <= amount; i++) {
                dp[i] += dp[i - x];
            }
        }
        return dp[amount];
    }
};