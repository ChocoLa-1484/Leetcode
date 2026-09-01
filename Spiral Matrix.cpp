class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans(m * n);
        int cnt = 0, dir = 1;
        int i = 0, j = 0, lim = n - 1;
        if (n == 1) dir = 2;
        while (cnt < m * n) {
            ans[cnt++] = matrix[i][j];
            if (dir % 4 == 1) {
                if (++j == lim) lim = m - ++dir / 4 - 1;
            } else if (dir % 4 == 2) {
                if (++i == lim) lim = ++dir / 4;
            } else if (dir % 4 == 3) {
                if (--j == lim) lim = ++dir / 4;
            } else {
                if (--i == lim) lim = n - ++dir / 4 - 1;
            }
        }
        return ans;
    }
};