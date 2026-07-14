class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    int subsequencePairCount(vector<int>& nums) {
        int n = ranges::max(nums);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> G(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++) {
                int g = gcd(i, j);
                G[i][j] = G[j][i] = g;
            }
        dp[0][0] = 1;
        for (const int x : nums) {
            auto nxt = dp;
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    int y, t = dp[i][j];
                    if (t == 0)  continue;
                    y = (i == 0 ? x : G[i][x]);
                    nxt[y][j] += t;
                    if (nxt[y][j] >= MOD)   nxt[y][j] -= MOD;
                    y = (j == 0 ? x : G[x][j]);
                    nxt[i][y] += t;
                    if (nxt[i][y] >= MOD)   nxt[i][y] -= MOD;
                }
            }
            dp.swap(nxt);
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += dp[i][i];
        }
        return ans % MOD;
    }
};