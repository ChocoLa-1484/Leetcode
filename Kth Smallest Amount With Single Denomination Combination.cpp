class Solution {
public:
    using ll = long long;
    long long findKthSmallest(vector<int>& coins, int k) {
        ranges::sort(coins);
        vector<int> v;
        for (const int x : coins) {
            bool f = true;
            for (const int y : v) {
                if (x % y == 0) {
                    f = false;
                    break;
                }
            }
            if (f)  v.push_back(x);
        }
        int n = v.size();
        int m = (1 << n);
        vector<int> bit_count(m);
        vector<ll> lcm(m, 1);
        ll l = k, r = 1LL * v[0] * k + 1;
        for (int mask = 1; mask < m; mask++) {
            int pre_mask = mask & (mask - 1);
            int i = __builtin_ctz(mask);
            ll tmp = lcm[pre_mask] / gcd(lcm[pre_mask], v[i]);
            lcm[mask] = tmp <= r / v[i] ? tmp * v[i] : r + 1;
        }
        auto get = [&](ll x) {
            ll ret = 0;
            for (int mask = 1; mask < m; mask++) {
                if (lcm[mask] > x)  continue;
                ret += __builtin_popcount(mask) & 1 ? x / lcm[mask] : -x / lcm[mask];
            }
            return ret;
        };
        while (l < r) {
            ll mid = l + ((r - l) >> 1);
            if (get(mid) >= k)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};