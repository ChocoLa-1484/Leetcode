class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> g(n);
        for (const auto& e : edges) {
            auto [u, v] = pair{e[0], e[1]};
            g[u].push_back(v);
            g[v].push_back(u);
        }
        // Euler Tour + Binary Lifting
        int LOG = bit_width((unsigned)n);
        vector up(LOG, vector<int>(n));
        vector<int> dep(n), tin(n), sz(n, 1), order;
        order.reserve(n);

        stack<int> st;
        st.push(0);

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            tin[u] = order.size();
            order.push_back(u);

            for (int v : g[u]) {
                if (v == up[0][u] && u != 0) continue;

                up[0][v] = u;
                dep[v] = dep[u] + 1;

                for (int j = 1; j < LOG; ++j)
                    up[j][v] = up[j - 1][up[j - 1][v]];

                st.push(v);
            }
        }
        
        for (int i = n - 1; i > 0; --i) {
            int u = order[i];
            sz[up[0][u]] += sz[u];
        }

        auto lca = [&](int u, int v) {
            if (dep[u] < dep[v]) swap(u, v);

            int d = dep[u] - dep[v];
            for (int j = 0; j < LOG; ++j)
                if ((d >> j) & 1)
                    u = up[j][u];

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; --j) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }
            return up[0][u];
        };

        vector<int> bit(n + 1);

        auto add = [&](int i, int x) {
            for (++i; i <= n; i += i & -i)
                bit[i] ^= x;
        };

        auto get = [&](int i) {
            int res = 0;
            for (++i; i > 0; i -= i & -i)
                res ^= bit[i];
            return res;
        };

        auto rangeXor = [&](int l, int r, int x) {
            add(l, x);
            if (r + 1 < n) add(r + 1, x);
        };

        auto mask = [](char c) {
            return 1 << (c - 'a');
        };

        // 初始化每個節點的根路徑 XOR
        for (int u = 0; u < n; ++u)
            rangeXor(tin[u], tin[u] + sz[u] - 1, mask(s[u]));

        vector<bool> ans;
        for (const string& q : queries) {
            istringstream ss(q);
            string op;
            int u;
            ss >> op >> u;

            if (op == "update") {
                char c;
                ss >> c;

                int delta = mask(s[u]) ^ mask(c);
                if (!delta) continue;

                rangeXor(tin[u], tin[u] + sz[u] - 1, delta);
                s[u] = c;
            } else {
                int v;
                ss >> v;

                int w = lca(u, v);
                int x = get(tin[u]) ^ get(tin[v]) ^ mask(s[w]);

                ans.push_back((x & (x - 1)) == 0);
            }
        }

        return ans;
    }
};