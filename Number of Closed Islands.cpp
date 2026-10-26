class Solution {
public:
    static constexpr int dx[] = {0, 1, 0, -1};
    static constexpr int dy[] = {1, 0, -1, 0};
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        auto bfs = [&]() {
            bool closed = true;
            while (!q.empty()) {
                auto [x, y] = q.front();  q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                        closed = false;
                        continue;
                    }
                    if (grid[nx][ny] == 1) continue;
                    grid[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            return closed;
        };
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) continue;
                grid[i][j] = 1;
                q.push({i, j});
                ans += bfs();
            }
        }
        return ans;
    }
};