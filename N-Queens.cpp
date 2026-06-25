class Solution {
public:
    vector<vector<string>> ans;
    bool valid(vector<int>& pos, int row, int col) {
        for (int r = 0; r < row; r++) {
            int c = pos[r];
            if (c == col)
                return false;
            if (abs(r - row) == abs(c - col))
                return false;
        }
        return true;
    }
    void dfs(int n, int r, vector<int>& pos) {
        if (r == n) {
            vector<string> tmp(n, string(n, '.'));
            for (int i = 0; i < n; i++) {
                tmp[i][pos[i]] = 'Q';
            }
            ans.push_back(tmp);
            return;
        }
        for (int c = 0; c < n; c++) {
            if (!valid(pos, r, c))   continue;
            pos[r] = c;
            dfs(n, r + 1, pos);
            pos[r] = -1;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> pos(n, -1);
        dfs(n, 0, pos);
        return ans;
    }
};