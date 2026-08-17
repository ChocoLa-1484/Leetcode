class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> pref(n + 1);
        partial_sum(stoneValue.begin(), stoneValue.end(), pref.begin() + 1);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        auto dfs = [&](this auto&& dfs, int l, int r) {
            if (l == r) return 0;
            if (dp[l][r] != -1) return dp[l][r];
            int ans = 0;
            for (int i = l; i < r; i++) {
                int l_sum = pref[i + 1] - pref[l];
                int r_sum = pref[r + 1] - pref[i + 1];
                if (l_sum < r_sum) {
                    ans = max(ans, l_sum + dfs(l, i));
                } else if (l_sum > r_sum) {
                    ans = max(ans, r_sum + dfs(i + 1, r));
                } else {
                    ans = max(ans, l_sum + max(dfs(l, i), dfs(i + 1, r)));
                }
            }
            return dp[l][r] = ans;
        };
        return dfs(0, n - 1);
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();