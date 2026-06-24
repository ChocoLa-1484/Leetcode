constexpr int MOD = 1e9 + 7;
using mat = vector<vector<int>>;

static inline mat mul(const mat& a, const mat& b) {
    int n = a.size();
    mat ret(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ret[i][j] = (ret[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return ret;
}
static inline mat mpow(mat x, int y) {
    int n = x.size();
    mat ret(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        ret[i][i] = 1;
    }
    while (y) {
        if (y & 1)  ret = mul(x, ret);
        x = mul(x, x);
        y >>= 1;
    }
    return ret;
}
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1, m2 = 2 * m;
        mat T(m2, vector<int>(m2, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++)
                T[j][i + m]++;
            for (int j = i + 1; j < m; j++)
                T[j + m][i]++;
        }
        vector<int> init(m2, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (i < j)  init[j + m]++;
                else if (i > j)   init[j]++;
            }
        }
        mat P = mpow(T, n - 2);
        int ans = 0;
        for (int i = 0; i < m2; i++) {
            for (int j = 0; j < m2; j++) {
                ans = (ans + 1LL * P[i][j] * init[j]) % MOD;
            }
        }
        return (int)ans;
    }
};