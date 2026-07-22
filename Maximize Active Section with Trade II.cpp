class SegTree {
private:
    int n;
    vector<int> a, seg;
    void build(int p, int l, int r) {
        if (l == r) {
            seg[p] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        seg[p] = max(seg[p << 1], seg[p << 1 | 1]);
    }
    int _query(int p, int l, int r, int L, int R) {
        if (L <= l && r <= R)
            return seg[p];
        int mid = (l + r) >> 1;
        int res = 0;
        if (L <= mid)
            res = max(res, _query(p << 1, l, mid, L, R));
        if (R > mid)
            res = max(res, _query(p << 1 | 1, mid + 1, r, L, R));
        return res;
    }
public:
    SegTree(const vector<int>& a) : a(a) {
        n = a.size();
        seg.resize(n << 2, 0);
        build(1, 0, n - 1);
    }
    int query(int L, int R) {
        if (L > R)  return 0;
        return _query(1, 0, n - 1, L, R);
    }
};
class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int cnt = count(s.begin(), s.end(), '1');
        vector<int> zeros, lb, rb;
        int i = 0;  // compress consecutive 0 into blocks.
        while (i < n) {
            int start = i;
            while (i < n && s[i] == s[start])
                i++;
            if (s[start] == '0') {
                zeros.emplace_back(i - start);
                lb.emplace_back(start);
                rb.emplace_back(i - 1);
            }
        }
        int m = zeros.size();
        int qn = queries.size(); // at least two zero blocks are needed.
        if (m < 2)  return vector<int>(qn, cnt);
        vector<int> tmp(m - 1); // sum of every two consecutive zeroBlocks
        for (int i = 0; i < m - 1; i++)
            tmp[i] = zeros[i] + zeros[i + 1];
        SegTree seg(tmp);
        vector<int> ans(qn);
        int k = 0;
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            // First zero block intersecting [l, r]
            int i = ranges::lower_bound(rb, l) - rb.begin();
            // Last zero block intersecting [l, r]
            int j = ranges::upper_bound(lb, r) - lb.begin() - 1;
            // Fewer than two zero blocks
            if (i > m - 1 || j < 0 || i >= j) {
                ans[k++] = cnt;
                continue;
            }
            // Length of the left partial zero block.
            int lLen = rb[i] - max(lb[i], l) + 1;
            // Length of the right partial zero block.
            int rLen = min(rb[j], r) - lb[j] + 1;
            // Exactly two zero blocks.
            if (i + 1 == j) {
                ans[k++] = (cnt + lLen + rLen);
                continue;
            }
            // Left partial block + next complete block.
            int v1 = lLen + zeros[i + 1];
            // Previous complete block + right partial block.
            int v2 = zeros[j - 1] + rLen;
            // Best pair of complete consecutive blocks in the middle
            int v3 = seg.query(i + 1, j - 2);
            ans[k++] = cnt + max({v1, v2, v3});
        }
        return ans;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

template <typename T, auto f>
class SparseTable {
public:
    vector<vector<T>> st;
    SparseTable(const vector<T>& nums) {
        int n = nums.size();
        int w = __lg(n) + 1;
        st.assign(w, vector<T>(n));
        for (int i = 0; i < n; i++)
            st[0][i] = nums[i];
        for (int i = 1; i < w; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    T query(int l, int r) { // [l, r)
        if (l >= r) return T{};
        int k = __lg(r - l);
        return f(st[k][l], st[k][r - (1 << k)]);
    }
};
class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int cnt = count(s.begin(), s.end(), '1');
        vector<int> zeros, lb, rb;
        int i = 0;  // compress consecutive 0 into blocks.
        while (i < n) {
            int start = i;
            while (i < n && s[i] == s[start])
                i++;
            if (s[start] == '0') {
                zeros.emplace_back(i - start);
                lb.emplace_back(start);
                rb.emplace_back(i - 1);
            }
        }
        int m = zeros.size();
        int qn = queries.size(); // at least two zero blocks are needed.
        if (m < 2)  return vector<int>(qn, cnt);
        vector<int> tmp(m - 1); // sum of every two consecutive zeroBlocks
        for (int i = 0; i < m - 1; i++)
            tmp[i] = zeros[i] + zeros[i + 1];
        SparseTable<int, [](int a, int b) constexpr {
            return max(a, b);
        }> st_mx(tmp);
        vector<int> ans(qn);
        int k = 0;
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            // First zero block intersecting [l, r]
            int i = ranges::lower_bound(rb, l) - rb.begin();
            // Last zero block intersecting [l, r]
            int j = ranges::upper_bound(lb, r) - lb.begin() - 1;
            // Fewer than two zero blocks
            if (i > m - 1 || j < 0 || i >= j) {
                ans[k++] = cnt;
                continue;
            }
            // Length of the left partial zero block.
            int lLen = rb[i] - max(lb[i], l) + 1;
            // Length of the right partial zero block.
            int rLen = min(rb[j], r) - lb[j] + 1;
            // Exactly two zero blocks.
            if (i + 1 == j) {
                ans[k++] = (cnt + lLen + rLen);
                continue;
            }
            // Left partial block + next complete block.
            int v1 = lLen + zeros[i + 1];
            // Previous complete block + right partial block.
            int v2 = zeros[j - 1] + rLen;
            // Best pair of complete consecutive blocks in the middle
            int v3 = st_mx.query(i + 1, j - 1);
            ans[k++] = cnt + max({v1, v2, v3});
        }
        return ans;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();