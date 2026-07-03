#define pii pair<int, int>
class Solution {
public:
    int n;
    vector<vector<pii>> g;
    vector<int> topo;
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n = online.size();
        g.resize(n);
        long long l = -1, r = -1;
        for (const auto& e : edges) {
            g[e[0]].emplace_back(e[1], e[2]);
            r = max(e[2] * 1ll, r);
        }
        topo = TopologicalSort();
        while (l < r) {
            long long mid = (l + r + 1) >> 1;
            if (check(online, mid, k)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
    bool check(const vector<bool>& online, int t, long long k) {
        vector<long long> dp(n, LLONG_MAX);
        dp[0] = 0;
        for (const int& u: topo) {
            if (dp[u] == LLONG_MAX) continue;
            if (!online[u]) continue;
            for (const auto& [v, w] : g[u]) {
                if (w < t || !online[v])   continue;
                dp[v] = min(dp[v], dp[u] + w);
            }
        }
        return dp.back() <= k;
    }
    vector<int> TopologicalSort(){
        vector<int> indeg(n);
        for (int i = 0; i < n; i++)
            for (const auto& [e, w] : g[i])
                indeg[e]++;
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indeg[i] == 0)  q.push(i);
        vector<int> topo;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for (const auto& [v, w] : g[u])
                if (--indeg[v] == 0)    q.push(v);
        }
        return topo;
    }
};