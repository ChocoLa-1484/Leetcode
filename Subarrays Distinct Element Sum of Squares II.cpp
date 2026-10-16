class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        vector<long long> bit1(n + 1), bit2(n + 1);
        vector<int> last(100005);

        auto update = [&](int pos, int value) {
            long long weighted = 1LL * (pos - 1) * value;
            for (int j = pos; j <= n; j += j & -j) {
                bit1[j] += value;
                bit2[j] += weighted;
            }
        };

        auto query = [&](int pos) {
            long long s1 = 0, s2 = 0;
            for (int j = pos; j > 0; j -= j & -j) {
                s1 += bit1[j];
                s2 += bit2[j];
            }
            return pos * s1 - s2;
        };

        long long s = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            int x = nums[i - 1], p = last[x];
            long long sum = query(i) - query(p);
            s = (s + 2 * sum + i - p) % MOD;
            ans = (ans + s) % MOD;
            update(p + 1, 1);
            update(i + 1, -1);
            last[x] = i;
        }
        return ans;
    }
};


using ll = long long;
static constexpr int MOD = 1e9 + 7;
class LazySegTree {
private:
    const int n;
    vector<ll> tree;
    vector<int> lazy;

    void apply(int p, int l, int r, int d) {
        tree[p] += 1LL * (r - l + 1) * d;
        lazy[p] += d;
    }

    void propagate(int p, int l, int r) {
        if (!lazy[p]) return;
        int mid = l + ((r - l) >> 1);
        apply(p << 1, l, mid, lazy[p]);
        apply(p << 1 | 1, mid + 1, r, lazy[p]);
        lazy[p] = 0;
    }

    ll _update(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            ll ret = tree[p];
            apply(p, l, r, 1);
            return ret;
        }
        propagate(p, l, r);
        int mid = l + ((r - l) >> 1);
        int pl = p << 1, pr = p << 1 | 1;
        ll ret = 0;
        if (ql <= mid)  ret += _update(pl, l, mid, ql, qr);
        if (qr > mid)  ret += _update(pr, mid + 1, r, ql, qr);
        tree[p] = tree[pl] + tree[pr];
        return ret;
    }
public:
    LazySegTree(int n) 
        : n(n), tree(n << 2), lazy(n << 2) {}
    ll update(int l, int r) { return _update(1, 0, n - 1, l, r); }
};

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const int n = nums.size();
        vector<int> last(100001, -1);
        LazySegTree tree(n);
        ll s = 0, ans = 0;
        for (int r = 0; r < n; ++r) {
            int x = nums[r], l = last[x];
            ll sum = tree.update(l + 1, r);
            s = (s + 2 * sum + r - l) % MOD; 
            ans = (ans + s) % MOD;
            last[x] = r;
        }
        return static_cast<int>(ans);
    }
};