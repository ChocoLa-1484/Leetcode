class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < m; i++) {
            vector<int> dpCur(n + 1);
            dpCur[0] = 1;
            for (int j = 1; j < n; j++) {
                dpCur[j] = dpCur[j - 1] + dp[j];
            }
            dp = dpCur;
        }
        return dp[n - 1];
    }
};