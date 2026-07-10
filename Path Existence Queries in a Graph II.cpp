#define pii pair<int, int>
class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> v(n);
        ranges::iota(v, 0);
        ranges::sort(v, {}, [&](int idx) { return nums[idx]; });
        vector<int> id(n);
        for (auto&& [i, val] : v | views:: enumerate) 
            id[val] = i;
        vector<vector<int>> st(18, vector<int>(n));
        int r = 0;
        for (int i = 0; i < n; i++) {
            if (r < i)  r = i;
            while (r + 1 < n && nums[v[r + 1]] - nums[v[r]] <= maxDiff && 
                   nums[v[r + 1]] - nums[v[i]] <= maxDiff)
                r++;
            st[0][i] = r;
        }
        for (int j = 1; j < 18; j++) {
            for (int i = 0; i < n; i++) {
                st[j][i] = st[j - 1][st[j - 1][i]];
            }
        }
        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            auto& q = queries[i];
            int l = id[q[0]], r = id[q[1]];
            if (l == r) {
                ans[i] = 0;
                continue;
            }
            if (l > r)  swap(l, r);
            int curr = l, sum = 0;
            for (int j = 17; j >= 0; j--) {
                if (st[j][curr] < r) {
                    curr = st[j][curr];
                    sum += (1 << j);
                }
            }
            ans[i] = (st[0][curr] >= r) ? sum + 1 : -1;
        }
        return ans;
    }
};