class Solution {
public:
    bool rows[9][9] = {};
    bool cols[9][9] = {};
    bool boxes[9][9] = {};
    vector<pair<int, int>> v;
    bool solved = false;
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    v.push_back({i, j});
                    continue;
                }
                int c = board[i][j] - '1', boxIndex = i / 3 * 3 + j / 3;
                rows[i][c] = cols[j][c] = boxes[boxIndex][c] = 1;
            }
        }
        dfs(0, board);
    }
    void dfs(int now, vector<vector<char>>& board) {
        if (now == v.size()) {
            solved = true;
            return;
        }
        int x = v[now].first, y = v[now].second;
        int boxIndex = x / 3 * 3 + y / 3;
        for (int c = 0; c < 9; c++) {
            if (rows[x][c] || cols[y][c] || boxes[boxIndex][c]) continue;
            board[x][y] = c + '1';
            rows[x][c] = cols[y][c] = boxes[boxIndex][c] = 1;
            dfs(now + 1, board);
            if (solved)    return;
            board[x][y] = '.';
            rows[x][c] = cols[y][c] = boxes[boxIndex][c] = 0;
        }
    }
};