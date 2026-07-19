class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        for (int i = 0; i < min(n, k); i++)
            pq.push({nums1[i] + nums2[0], i, 0});
        vector<vector<int>> ans;
        ans.reserve(k);
        while (!pq.empty() && k--) {
            auto [v, i, j] = pq.top();
            pq.pop();
            ans.push_back({nums1[i], nums2[j]});
            if (j + 1 < m)
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
        }
        return ans;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();