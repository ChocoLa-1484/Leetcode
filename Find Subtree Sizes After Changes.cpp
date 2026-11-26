class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = ssize(parent);
        vector<vector<int>> g(n);
        for (int i = 1; i < n; ++i) g[parent[i]].push_back(i);
        int last[26];
        memset(last, -1, sizeof(last));
        vector<int> ans(n, 1);
        auto dfs = [&](this auto&& dfs, int i) -> int {
            int pre = last[s[i] - 'a'];
            last[s[i] - 'a'] = i;
            for (auto j : g[i]) {
                int nxt = last[s[j] - 'a'] == -1 ? i : last[s[j] - 'a'];
                ans[nxt] += dfs(j);
            }
            last[s[i] - 'a'] = pre;
            return ans[i];
        };
        dfs(0);
        return ans;
    }
};