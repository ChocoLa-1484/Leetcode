class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<pair<int, int>> g[n];
        for (const auto& e : edges) {
            auto [u, v, w] = array{e[0], e[1], e[2]};
            g[u].emplace_back(v, w);
        }
        vector dist(n, vector<int>(k + 1, INT_MAX));
        using State = array<int, 3>;
        priority_queue<State, vector<State>, greater<>> pq;
        dist[0][1] = 0;
        pq.push({0, 0, 1});
        while (!pq.empty()) {
            auto [d, u, cnt] = pq.top(); pq.pop();
            if (d > dist[u][cnt])  continue;
            if (u == n - 1) return d;
             for (auto [v, w] : g[u]) {
                int nc = labels[u] == labels[v] ? cnt + 1 : 1;
                int nd = d + w;
                if (nc > k || nd >= dist[v][nc]) continue;
                dist[v][nc] = nd;
                pq.push({nd, v, nc});
            }
        }
        return -1;
    }
};