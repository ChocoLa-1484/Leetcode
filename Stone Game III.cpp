class Solution {
public:
    static constexpr inline string s[3] = {"Bob", "Tie", "Alice"};
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int dp[4]{};
        for (int i = n - 1; i >= 0; i--) {
            int MAX = INT_MIN, cur = 0;
            for (int k = 0; k < 3 && i + k < n; k++) {
                cur += stoneValue[i + k];
                MAX = max(MAX, cur - dp[(i + k + 1) & 3]);
            }
            dp[i & 3] = MAX;
        }
        return s[clamp(dp[0], -1, 1) + 1];
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();