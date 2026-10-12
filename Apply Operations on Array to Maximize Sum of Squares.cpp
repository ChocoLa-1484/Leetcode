class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    static constexpr int N = 31;
    int maxSum(vector<int>& nums, int k) {
        int bit[N] = {};
        for (const int x : nums) {
            for (int i = 0; i < N; ++i) {
                if ((x >> i) & 1)   bit[i]++;
            }
        }
        long long ans = 0;
        while (k--) {
            long long x = 0;
            for (int i = 0; i < N; ++i) {
                if (bit[i]) {
                    x |= (1 << i);
                    bit[i]--;
                }
            }
            ans += x * x;
            if (ans >= MOD)  ans %= MOD;
        }
        return ans;
    }
};