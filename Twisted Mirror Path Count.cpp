class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    int uniquePaths(vector<vector<int>>& grid) {
        const int n = grid[0].size();
        vector<int> dp(n);
        dp[0] = 1;
        for (const auto& row : grid) {
            for (int j = 0, l = 0; j < n; j++) {
                if (row[j]) {
                    swap(l, dp[j]);
                } else {
                    l += dp[j];
                    if (l >= MOD)   l -= MOD;
                    dp[j] = l;
                }
            }
        }
        return dp.back();
    }
};