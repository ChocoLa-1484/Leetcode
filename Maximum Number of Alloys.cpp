class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int ans = -1;
        int mx = ranges::min(stock) + budget;
        for (const auto& m : composition) {
            auto check = [&](int unit) {
                long long b = 0;
                for (int i = 0; i < n; i++) {
                    b += max(0LL, (1LL * m[i] * unit - stock[i])) * cost[i];
                    if (b > budget) return false;
                }
                return true;
            };
            int l = ans, r = mx + 1;
            while (l + 1 < r) {
                int mid = l + ((r - l) >> 1);
                (check(mid) ? l : r) = mid;
            }
            ans = l;
        }
        return ans;
    }
};