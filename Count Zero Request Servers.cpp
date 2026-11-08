class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        ranges::sort(logs, {}, [](auto& log) { return log[1]; });
        logs.push_back({0, INT_MAX});
        int m = queries.size();
        vector<int> ans(m), idx(m);
        ranges::iota(idx, 0);
        ranges::sort(idx, {}, [&](int i) { return queries[i]; });
        
        vector<int> cnt(n + 1);
        int lo = 0, hi = 0, cur = 0;
        for (const int i : idx) {
            int q = queries[i];
            for (; logs[hi][1] <= q; ++hi) cur += cnt[logs[hi][0]]++ == 0;
            for (; logs[lo][1] < q - x; ++lo) cur -= --cnt[logs[lo][0]] == 0;
            ans[i] = n - cur; 
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