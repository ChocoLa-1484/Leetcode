class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        int suf = 0;
        for (int i = n - 1; i >= 0; --i) {
            suf += piles[i];
            for (int M = 1; M <= n; ++M) {
                if (i + 2 * M >= n) {
                    dp[i][M] = suf;
                } else {
                    int MIN = INT_MAX;
                    for (int j = 1; j <= 2 * M; ++j)
                        MIN = min(MIN, dp[i + j][max(M, j)]);
                    dp[i][M] = suf - MIN;
                }
            }
        }
        return dp[0][1];
    }
};