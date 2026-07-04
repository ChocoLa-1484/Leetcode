class DSU {
public:
    vector<int> pa, sz, mn;
    DSU(int n) : pa(n), sz(n, 1), mn(n, INT_MAX) { ranges::iota(pa, 0); }
    int find(int x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }
    void merge(int x, int y, int d) {
        x = find(x), y = find(y);
        if (x == y) {
            mn[x] = min({mn[x], mn[y], d});
            return;
        }
        if (sz[x] < sz[y])  swap(x, y);
        pa[y] = x;
        sz[x] += sz[y];
        mn[x] = min({mn[x], mn[y], d});
    }
    int query(int x) {
        return mn[find(x)];
    }
};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DSU dsu(n + 1);
        for (auto& e : roads) {
            dsu.merge(e[0], e[1], e[2]);
        }
        return dsu.query(n);
    }
};