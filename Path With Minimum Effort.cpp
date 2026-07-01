class Solution {
    static constexpr pair<int, int> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<array<int, 3>> pq;
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        pq.push({0, 0, 0});
        while (!pq.empty()) {
            auto [val, x, y] = pq.top();
            pq.pop();
            if (x == n - 1 && y == m - 1)
                return -val;
            if (-val > dist[x][y])
                continue;

            for (auto& [dx, dy] : dir) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                int v = max(-val, abs(heights[x][y] - heights[nx][ny]));
                if (v < dist[nx][ny]) {
                    pq.push({-v, nx, ny});
                    dist[nx][ny] = v;
                }
            }
        }
        return 0;
    }
};