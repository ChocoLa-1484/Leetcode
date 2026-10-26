class Solution {
public:
    static constexpr int dx[] = {0, 1, 0, -1};
    static constexpr int dy[] = {1, 0, -1, 0};
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        auto bfs = [&](int x, int y) -> bool {
            long long sum = grid[x][y];
            grid[x][y] = 0;
            q.emplace(x, y);
            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || !grid[nx][ny]) continue;
                    sum += grid[nx][ny];
                    grid[nx][ny] = 0;
                    q.emplace(nx, ny);
                }
            }
            return sum % k == 0;
        };
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;
                ans += bfs(i, j);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int N = m * n;
        vector<int> pa(N), sz(N, 1);
        vector<long long> sum(N);
        ranges::iota(pa, 0);
        auto find = [&](this auto&& find, int x) -> int {
            return pa[x] == x ? x : pa[x] = find(pa[x]);
        };
        auto merge = [&](int x, int y) {
            x = find(x), y = find(y);
            if (x == y) return;
            if (sz[x] < sz[y])  swap(x, y);
            pa[y] = x;
            sz[x] += sz[y];
            sum[x] += sum[y];
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;
                int id = i * n + j;
                sum[id] = grid[i][j];
                if (i && grid[i - 1][j]) merge(id, id - n);
                if (j && grid[i][j - 1]) merge(id, id - 1);
            }
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (pa[i] == i && sum[i] && sum[i] % k == 0) ans++;
        }
        return ans;
    }
};