class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = ranges::max(nums);
        vector<int> cnt(mx + 1);
        for (const int i : nums)  cnt[i]++;
        vector<long long> v(mx + 1);
        for (int d = mx; d >= 1; d--) {
            long long c = 0;
            for (int m = d; m <= mx; m += d)
                c += cnt[m];
            v[d] = c * (c - 1) / 2;
            for (int m = d + d; m <= mx; m += d)
                v[d] -= v[m];
        }
        partial_sum(v.begin() + 1, v.end(), v.begin() + 1);
        int n = queries.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            ans[i] = lower_bound(v.begin() + 1, v.end(), queries[i] + 1) - v.begin();
        return ans;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();