class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector ans(n, vector<int>(n, 0));
        int x = 0, y = 0, dx = 1, dy = 0;
        for (int i = 1; i <= n * n; i++) {
            ans[y][x] = i;
            if (x + dx >= n || x + dx < 0 || y + dy >= n || y + dy < 0 || ans[y + dy][x + dx] != 0) {
                swap(dx, dy);
                dx = -dx;
            }
            x += dx;
            y += dy;
        }
        return ans;
    }
};