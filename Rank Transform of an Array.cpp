class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> v(n);
        for (auto&& [i, val]: arr | views::enumerate)
            v[i] = {arr[i], i};
        ranges::sort(v);
        vector<int> ans(n);
        int rank = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 || v[i - 1].first != v[i].first)
                rank++;
            ans[v[i].second] = rank;
        }
        return ans;
    }
};