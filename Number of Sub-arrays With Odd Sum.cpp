class Solution {
public
    static constexpr int MOD = 1e9 + 7;
    int numOfSubarrays(vectorint& arr) {
        int n = arr.size();
        int odd = 0, even = 0;
        long long ans = 0;
        for (const int x  arr) {
            if (x & 1) {
                swap(even, odd);
                ++odd;
            } else {
                ++even;
            }
            ans += odd;
            if (ans = MOD) ans -= MOD;
        }
        return static_castint(ans);

    }
};