class Solution {
public:
    // Gosper's Hack: 產生下一個相同 popcount 的二進制數
    int next_popcount(int n) {
        int c = (n & -n), r = n + c;
        return (((r ^ n) >> 2) / c) | r;
    }
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        for (int i = (1 << numSelect) - 1; i < (1 << n); i = next_popcount(i)) {
            int cur = 0;
            for (int j = 0, k = 0; j < m; j++) {
                for (k = 0; k < n; k++) {
                    if (matrix[j][k] && !(i >> k & 1))
                        break;
                }
                cur += k == n;
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};