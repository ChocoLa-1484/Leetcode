class Solution {
    static constexpr pair<int, int> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        priority_queue<array<int, 3>> pq;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = grid[0][0];
        pq.push({-grid[0][0], 0, 0});
        while (!pq.empty()) {
            auto [val, x, y] = pq.top();
            pq.pop();
            if (x == n - 1 && y == m - 1)
                return -val < health;
            if (-val > dist[x][y])
                continue;
            for (auto& [dx, dy] : dir) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                int v = -val + grid[nx][ny];
                if (v < dist[nx][ny]) {
                    pq.push({-v, nx, ny});
                    dist[nx][ny] = v;
                }
            }
        }
        return 0;
    }
};

#define pii pair<int, int>
class Solution {
    static constexpr int dx[4] = {1, 0, -1, 0};
    static constexpr int dy[4] = {0, 1, 0, -1};
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        deque<pii> dq;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = grid[0][0];
        dq.emplace_front(0, 0);
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            if (dist[x][y] >= health)   return false;
            if (x == n - 1 && y == m - 1)   return true;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                int v = dist[x][y] + grid[nx][ny];
                if (v >= dist[nx][ny]) 
                    continue;
                dist[nx][ny] = v;
                grid[nx][ny] ? dq.emplace_back(nx, ny) : dq.emplace_front(nx, ny);
            }
        }
        return 0;
    }
};