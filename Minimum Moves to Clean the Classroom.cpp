class Solution {
public:
    static constexpr int dx[4] = {1, -1, 0, 0};
    static constexpr int dy[4] = {0, 0, 1, -1};
    int minMoves(vector<string>& classroom, int energy) {
        int sx, sy, cnt = 0;
        int m = classroom.size(), n = classroom[0].length();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'L') classroom[i][j] = '0' + cnt++;
                if (classroom[i][j] == 'S') sx = i, sy = j;
            }
        }
        queue<tuple<int, int, int, int>> q;
        vector best(m, vector(n, vector<int>(1 << cnt, -1)));
        best[sx][sy][0] = energy;
        q.emplace(sx, sy, energy, 0);
        int step = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y, e, mask] = q.front();
                q.pop();
                if (mask == (1 << cnt) - 1)   return step;
                if (e == 0) continue;
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx == m || nx < 0 || ny == n || ny < 0 || classroom[nx][ny] == 'X') continue;
                    int ne = classroom[nx][ny] == 'R' ? energy : e - 1;
                    int nmask = mask;
                    if ('0' <= classroom[nx][ny] && classroom[nx][ny] <= '9')
                        nmask |= 1 << (classroom[nx][ny] - '0');
                    if (ne > best[nx][ny][nmask]) {
                        best[nx][ny][nmask] = ne;
                        q.emplace(nx, ny, ne, nmask);
                    }
                }
            }
            step++;
        }      
        return -1;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();