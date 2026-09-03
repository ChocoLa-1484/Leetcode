class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<uint8_t> col(n), diag1((n << 1) - 1), diag2((n << 1) - 1);
        auto dfs = [&](this auto&& dfs, int r) {
            if (r == n) {
                ans.emplace_back(board);
                return;
            }
            for (int c = 0; c < n; c++) {
                if (col[c] || diag1[r + c] || diag2[r - c + n - 1]) continue;
                board[r][c] = 'Q';
                col[c] = diag1[r + c] = diag2[r - c + n - 1] = true;
                dfs(r + 1);
                board[r][c] = '.';
                col[c] = diag1[r + c] = diag2[r - c + n - 1] = false;
            }
        };
        dfs(0);
        return ans;
    }
};