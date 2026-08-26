class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int n = aliceArrows.size();
        vector<int> ans(n), path(n);
        int mx = -1, now = 0;
        auto dfs = [&](this auto&& dfs, int i) {
            if (i == n || numArrows == 0) {
                if (now > mx) {
                    mx = now;
                    ans = path;
                    if (numArrows != 0)
                        ans[0] += numArrows;
                }
                return;
            }
            dfs(i + 1);
            if (numArrows - (aliceArrows[i] + 1) >= 0) {
                path[i] = aliceArrows[i] + 1;
                numArrows -= path[i];
                now += i;
                dfs(i + 1);
                numArrows += path[i];
                path[i] = 0;
                now -= i;
            }
        };
        dfs(0);
        return ans;
    }
};