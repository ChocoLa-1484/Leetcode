class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) 
            v[i] = {nums[i], i};
        ranges::sort(v);
        vector<int> ans(n), idx;
        idx.reserve(n);
        for (int l = 0; l < n;) {
            idx.clear();
            idx.push_back(v[l].second);
            int r = l + 1;
            while (r < n && v[r].first - v[r - 1].first <= limit) {
                idx.push_back(v[r++].second);
            }
            ranges::sort(idx);
            for (int i = l; i < r; i++)
                ans[idx[i - l]] = v[i].first;
            l = r;
        }
        return ans;
    }
};