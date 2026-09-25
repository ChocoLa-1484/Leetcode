struct Node {
    int cnt[5]{};
    int mul = 1;
    inline void init(int x) {
        *this = {};
        mul = x;
        cnt[x] = 1;
    }
};
class SegTree {
private:
    int n, k;
    vector<int> a;
    vector<Node> tree;
    
    Node merge(const Node& left, const Node& right) {
        Node ret;
        for (int i = 0; i < k; i++) {
            ret.cnt[i] += left.cnt[i];
            ret.cnt[left.mul * i % k] += right.cnt[i];
        }
        ret.mul = left.mul * right.mul % k;
        return ret;
    }
    void build(int p, int l, int r) {
        if (l == r) {
            tree[p].init(a[l] % k);
            return;
        }
        int mid = (l + r) >> 1;
        int pl = p << 1, pr = p << 1 | 1;
        build(pl, l, mid);
        build(pr, mid + 1, r);
        tree[p] = merge(tree[pl], tree[pr]);
    }
    Node _query(int p, int l, int r, int L, int R) {
        if (L <= l && r <= R)
            return tree[p];
        int mid = (l + r) >> 1;
        int pl = p << 1, pr = p << 1 | 1;
        if (R <= mid)   return _query(pl, l, mid, L, R);
        if (L > mid)    return _query(pr, mid + 1, r, L, R);
        return merge(_query(pl, l, mid, L, R), _query(pr, mid + 1, r, L, R));
    }
    void _update(int p, int l, int r, int pos, int val) {
        if (l == r) {
            tree[p].init(val % k);
            return;
        }
        int mid = (l + r) >> 1;
        int pl = p << 1, pr = p << 1 | 1;
        if (pos <= mid)
            _update(pl, l, mid, pos, val);
        else
            _update(pr, mid + 1, r, pos, val);
        tree[p] = merge(tree[pl], tree[pr]);
    }
public:
    SegTree(const vector<int>& a, const int k) : n(a.size()), k(k), a(a), tree(n << 2) {
        build(1, 0, n - 1);
    }
    inline void update(int pos, int val) {
        _update(1, 0, n - 1, pos, val);
    }
    inline int query(int L, int R, int x) {
        if (L > R)  return 0;
        return _query(1, 0, n - 1, L, R).cnt[x];
    }
};
class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size(), qn = queries.size();
        SegTree seg(nums, k);
        vector<int> ans(qn);
        for (const auto& [i, q] : queries | views::enumerate) {
            seg.update(q[0], q[1]);
            ans[i] = seg.query(q[2], n - 1, q[3]);
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