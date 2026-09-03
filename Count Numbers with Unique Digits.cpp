class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        bool vis[10] = {};
        int ans = 0;
        bool z = true;
        auto dfs = [&](this auto&& dfs, int i) {
            if (i == n) {
                ans++;
                return;
            }
            for (int j = 0; j <= 9; j++) {
                if (vis[j]) {
                    if (j != 0) continue;
                    if (!z) continue;
                }
                if (j != 0) z = false;
                vis[j] = true;
                dfs(i + 1);
                if (j != 0) z = true;
                vis[j] = false;
            }
        };
        dfs(0);
        return ans;
    }
};