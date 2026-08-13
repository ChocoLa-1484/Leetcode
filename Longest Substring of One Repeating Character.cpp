struct Node {
    char lc, rc;
    int lcnt, rcnt;
    int max_len;
};
class SegTree {
private:
    int n;
    vector<Node> tree;
    inline Node merge(const Node& left, const Node& right, int len_l, int len_r) {
        Node res;
        res.lc = left.lc;
        res.rc = right.rc;
        res.lcnt = left.lcnt;
        res.rcnt = right.rcnt;
        res.max_len = max(left.max_len, right.max_len);
        if (left.rc == right.lc) {
            res.max_len = max(res.max_len, left.rcnt + right.lcnt);
            if (left.lcnt == len_l) res.lcnt += right.lcnt;
            if (right.rcnt == len_r) res.rcnt += left.rcnt;
        }
        return res;
    }
    void build(const string& s, int p, int l, int r) {
        if (l == r) {
            tree[p] = {s[l], s[l], 1, 1, 1};
            return;
        }
        int mid = (l + r) >> 1;
        int nl = p << 1, nr = p << 1 | 1;
        build(s, nl, l, mid);
        build(s, nr, mid + 1, r);
        tree[p] = merge(tree[nl], tree[nr], mid - l + 1, r - mid);
    }
    void _update(int p, int l, int r, int pos, char val) {
        if (l == r) {
            tree[p] = {val, val, 1, 1, 1};
            return;
        }
        int mid = (l + r) >> 1;
        int nl = p << 1, nr = p << 1 | 1;
        if (pos <= mid)
            _update(nl, l, mid, pos, val);
        else
            _update(nr, mid + 1, r, pos, val);
        tree[p] = merge(tree[nl], tree[nr], mid - l + 1, r - mid);
    }
public:
    SegTree(const string& s) {
        n = s.length();
        tree.resize(n << 2);
        build(s, 1, 0, n - 1);
    }
    inline void update(int pos, char val) {
        _update(1, 0, n - 1, pos, val);
    }
    inline int query() const {
        return tree[1].max_len;
    }
};
class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegTree seg(s);
        int q = queryCharacters.size();
        vector<int> ans(q);
        for (int i = 0; i < q; i++) {
            seg.update(queryIndices[i], queryCharacters[i]);
            ans[i] = seg.query();
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