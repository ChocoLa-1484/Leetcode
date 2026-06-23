#define ll long long
static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        vector<ll> up(m + 1), down(m + 1);
        vector<ll> up_pre(m + 1, 0), down_pre(m + 1, 0);
        for (int j = 1; j <= m; j++) {
            up[j] = j - 1;
            down[j] = m - j;
        }
        for (int len = 3; len <= n; len++) {
            partial_sum(up.begin(), up.end(), up_pre.begin(),
                        [](ll a, ll b) { return (a + b) % MOD; });
            partial_sum(down.begin(), down.end(), down_pre.begin(),
                        [](ll a, ll b) { return (a + b) % MOD; });
            for (int j = 1; j <= m; j++) {
                up[j] = down_pre[j - 1];
                down[j] = (up_pre[m] - up_pre[j] + MOD) % MOD;
            }
        }
        ll ans = 0;
        for (int i = 1; i <= m; i++) {
            ans += (up[i] + down[i]) % MOD;
            ans %= MOD;
        }
        return (int)ans;
    }
};