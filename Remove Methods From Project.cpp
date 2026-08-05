class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> g;
        g.resize(n);
        for (const auto& e : invocations) 
            g[e[0]].emplace_back(e[1]);
        bitset<100005> vis;
        queue<int> q;
        q.push(k);
        vis.set(k);
        while (!q.empty()) {
            int u = q.front();  q.pop();
            for (const auto& v : g[u]) {
                if (vis.test(v))    continue;
                q.push(v);
                vis.set(v);
            }
        }
        for (const auto& e : invocations) {
            if (!vis.test(e[0]) && vis.test(e[1])) {
                vector<int> ans(n);
                ranges::iota(ans, 0);
                return ans;
            }
        }
        vector<int> ans(n - vis.count());
        for (int i = 0, j = 0; i < n; i++) {
            if (!vis.test(i))    ans[j++] = i;
        }
        return ans;
    }
};