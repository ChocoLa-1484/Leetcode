class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if ((n + m - 1) & 1 || grid.back().back() == '(' || grid[0][0] == ')')  return false;
        bitset<128> dp[101]{};
        dp[1].set(0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                auto mask = dp[j] | dp[j + 1];
                dp[j + 1] = grid[i][j] == '(' ? mask << 1 : mask >> 1;
            }
        }
        return dp[m].test(0);
    }
};

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int total = n + m - 1;
        if (total & 1)  return false;
        vector memo(n, vector<vector<int>>(m, vector<int>(total + 1, -1)));
        auto dfs = [&](this auto&& dfs, int x, int y, int sum) -> bool {
            if (sum < 0 || (sum << 1) > total)   return false;
            if (x == m - 1 && y == n - 1)   return sum == 0;
            if (memo[y][x][sum] != -1)  return memo[y][x][sum];
            bool ans = (y + 1 < n && dfs(x, y + 1, sum + (grid[y + 1][x] == '(' ? 1 : -1))) ||
                       (x + 1 < m && dfs(x + 1, y, sum + (grid[y][x + 1] == '(' ? 1 : -1)));
            return memo[y][x][sum] = ans;
        };
        return dfs(0, 0, grid[0][0] == '(' ? 1 : -1);
    }
};