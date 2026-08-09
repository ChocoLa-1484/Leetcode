class Solution {
    int memo[101][101];
    int suf[101];
    int dfs(int i, int M, const int n) {
        if (i + 2 * M >= n) return suf[i];
        if (memo[i][M] != -1)   return memo[i][M];
        int MIN = INT_MAX;
        for (int X = 1; X <= 2 * M; ++X)
            MIN = min(MIN, dfs(i + X, max(M, X), n));
        return memo[i][M] = suf[i] - MIN;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        memset(memo, -1, sizeof(memo));
        suf[n] = 0;
        for (int i = n - 1; i >= 0; --i)
            suf[i] = suf[i + 1] + piles[i];
        return dfs(0, 1, n);
    }
};