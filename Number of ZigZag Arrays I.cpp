#define ll long long
static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        vector<vector<ll>> down(n + 1, vector<ll>(m + 1));
        vector<vector<ll>> up(n + 1, vector<ll>(m + 1));
        for (int j = 1; j <= m; j++) {
            up[2][j] = j - 1;
            down[2][j] = m - j;
        }
        vector<ll> down_pre(m + 1, 0);
        vector<ll> up_pre(m + 1, 0);
        for (int len = 3; len <= n; len++) {
            partial_sum(down[len - 1].begin(), down[len - 1].end(), down_pre.begin(),
                            [](ll a, ll b) { return (a + b) % MOD; });
            partial_sum(up[len - 1].begin(), up[len - 1].end(), up_pre.begin(),
                            [](ll a, ll b) { return (a + b) % MOD; });
            for (int j = 1; j <= m; j++) {
                up[len][j] = down_pre[j - 1];
                down[len][j] = (up_pre[m] - up_pre[j] + MOD) % MOD;
            }
        }
        ll ans = 0;
        for (int i = 1; i <= m; i++) {
            ans += (up[n][i] + down[n][i]) % MOD;
            ans %= MOD;
        }
        return (int)ans;
    }
};