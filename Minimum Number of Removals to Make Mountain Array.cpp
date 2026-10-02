class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> suf(n), v;
        v.reserve(n);
        for (const auto& [i, x] : nums | views::enumerate) {
            auto it = ranges::lower_bound(v, x);
            suf[i] = it - v.begin() + 1;
            if (it == v.end())  v.push_back(x);
            else    *it = x;
        }
        v.clear();
        int pre, mx = 0;
        for (const auto& [i, x] : nums | views::enumerate | views::reverse) {
            auto it = ranges::lower_bound(v, x);
            pre = it - v.begin() + 1;
            if (it == v.end())  v.push_back(x);
            else    *it = x;
            if (pre >= 2 && suf[i] >= 2)    mx = max(mx, pre + suf[i] - 1);
        }
        return n - mx;
    }
};