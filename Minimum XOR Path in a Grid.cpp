class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<bitset<1024>> dp(n);
        dp[0].set(grid[0][0]);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                auto cur = j ? dp[j] | dp[j - 1] : dp[j];
                dp[j].reset();
                for (int k = cur._Find_first(); k < 1024; k = cur._Find_next(k)) {
                    dp[j].set(k ^ grid[i][j]);
                }
            }
        }
        return dp.back()._Find_first();
    }
};

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector vis(m, vector<bitset<1024>>(n));
        int ans = 1024;

        auto dfs = [&](this auto&& dfs, int i, int j, int x) -> void {
            x ^= grid[i][j];
            if (i == m - 1 && j == n - 1) {
                ans = min(ans, x);
                return;
            }
            if (ans == 0) return;
            if (vis[i][j].test(x) ) return;
            vis[i][j].set(x);

            if (i + 1 < m) dfs(i + 1, j, x);
            if (j + 1 < n) dfs(i, j + 1, x);
        };

        dfs(0, 0, 0);
        return ans;
    }
};

class Solution {
public:
    using Bits = array<uint64_t, 16>;
    int minCost(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        bool transposed = n > m;
        const int w = min(m, n), h = max(m, n);
        if (w == 1) {
            int ans = 0;
            for (const auto& row : grid)
                for (const int x : row)
                    ans ^= x;
            return ans;
        }
        static const auto masks = [] {
            array<uint64_t, 6> masks{};
            for (int bit = 0; bit < 6; ++bit) {
                int shift = 1 << bit;
                for (int i = 0; i < 64; ++i)
                    if (!(i & shift))
                        masks[bit] |= 1ULL << i;
            }
            return masks;
        }();
        vector<Bits> dp(w);
        dp[0][0] = 1;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                auto& cur = dp[j];
                if (j) {
                    for (int k = 0; k < 16; ++k)
                        cur[k] |= dp[j - 1][k];
                }
                for (unsigned val = transposed ? grid[j][i] : grid[i][j]; val; val -= val & -val) {
                    int bit = countr_zero(val);
                    if (bit < 6) {
                        int shift = 1 << bit;
                        uint64_t mask = masks[bit];
                        for (auto& x : cur)
                            x = ((x & mask) << shift) | ((x & ~mask) >> shift);
                    } else {
                        int shift = 1 << (bit - 6);
                        for (int k = 0; k < 16; ++k)
                            if (!(k & shift))
                                swap(cur[k], cur[k | shift]);
                    }
                }
            }
        }
        for (int k = 0; k < 16; ++k)
            if (dp.back()[k]) return (k << 6) + countr_zero(dp.back()[k]);
        return -1;
    }
};