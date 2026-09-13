class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<int> b1(n, 0), b2(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j]) b1[i] |= (1 << j);
                if (img2[i][j]) b2[i] |= (1 << j);
            }
        }
        int ans = 0;
        for (int dy = -n + 1; dy < n; dy++) {
            for (int dx = -n + 1; dx < n; dx++) {
                int sum = 0;
                for (int i = 0; i < n; i++) {
                    int ny = dy + i;
                    if (ny < 0 || ny >= n)  continue;
                    int nx = (dx >= 0) ? (b1[i] << dx) : (b1[i] >> -dx);
                    sum += __builtin_popcount(nx & b2[ny]);
                }
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};