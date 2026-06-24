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
vector<int> mulMV(const mat& T, const vector<int>& v) {
    int n = T.size();
    vector<int> ret(n);
    for (int i = 0; i < n; i++) {
        long long cur = 0;
        for (int j = 0; j < n; j++) {
            cur += 1LL * T[i][j] * v[j];
        }
        ret[i] = cur % MOD;
    }
    return ret;
}

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
        mat U(m, vector<int>(m)), L(m, vector<int>(m));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < i; j++)
                U[i][j] = L[j][i] = 1;
        n--;
        mat UL = mul(U, L);
        mat P = mpow(UL, n >> 1);
        if (n & 1)  P = mul(L, P);
        long long ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++){
                ans = (ans + 1LL * P[i][j]) % MOD;
            }
        }
        return (int)(ans * 2) % MOD;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();