class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        using T = array<int, 4>;
        vector<T> v(n);
        for (const auto& [i, x] : intervals | views::enumerate) {
            v[i] = {x[0], x[1], x[2], static_cast<int>(i)};
        }
        ranges::sort(v, {}, [](const T& a) { return a[1]; });
        vector path(n + 1, vector<vector<int>>(5));
        vector dp(n + 1, vector<long long>(5));
        for (int k = 1; k <= 4; k++) {
            for (int i = 0; i < n; i++) {
                int j = lower_bound(v.begin(), v.begin() + i, v[i][0], [](const T& a, const int val) {
                    return a[1] < val;
                }) - v.begin();
                long long skip = dp[i][k];
                long long take = dp[j][k - 1] + v[i][2];
                if (skip > take) {
                    dp[i + 1][k] = skip;
                    path[i + 1][k] = path[i][k];
                } else {
                    dp[i + 1][k] = take;
                    vector<int> new_path = path[j][k - 1];
                    new_path.push_back(v[i][3]);
                    ranges::sort(new_path);
                    if (skip == take && path[i][k] < new_path)
                        path[i + 1][k] = path[i][k];
                    else
                        path[i + 1][k] = move(new_path);
                }
            }
        }
        return path.back().back();
    }
};