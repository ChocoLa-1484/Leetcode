class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 0; i < m; i++) {
            vector<int> dpCur(n + 1, 0);
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j]) continue;
                dpCur[j + 1] = dpCur[j] + dp[j + 1];
            }
            dp = dpCur;
        }
        return dp[n];
    }
};