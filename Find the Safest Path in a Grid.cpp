#define pii pair<int, int>
class Solution {
    static constexpr pii dirs[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pii> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j])
                    q.push({i, j});
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (auto& [dx, dy] : dirs) {
                int x = i + dx;
                int y = j + dy;
                if (x >= 0 && y >= 0 && x < n && y < n && !grid[x][y]) {
                    grid[x][y] = grid[i][j] + 1;
                    q.push({x, y});
                }
            }
        }
        priority_queue<array<int, 3>> pq;
        pq.push({grid[0][0], 0, 0});
        grid[0][0] = -grid[0][0];
        while (!pq.empty()) {
            auto [val, i, j] = pq.top();
            pq.pop();
            if (i == n - 1 && j == n - 1)
                return val - 1;
            for (auto& [dx, dy] : dirs) {
                int x = i + dx;
                int y = j + dy;
                if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] > 0) {
                    pq.push({min(val, grid[x][y]), x, y});
                    grid[x][y] = -grid[x][y];
                }
            }
        }
        return grid.back().back() - 1;
    }
};